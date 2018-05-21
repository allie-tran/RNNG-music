import argparse
import os
from numpy import argmax

parser = argparse.ArgumentParser()
parser.add_argument('--num_steps', default=50, type=int, help='The total number of steps the generated melodies should be, priming '
	'melody length + generated steps. Each step is a 16th of a bar.' )
parser.add_argument('--primer_melody', default = '1', help='If specified, this melody will be '
	'used as the priming melody. If a priming melody is not specified, '
	'melodies will be generated from scratch.')
parser.add_argument('--temperature', default=1.0, help = 'The randomness of the generated melodies. 1.0 uses the unaltered softmax '
	'probabilities, greater than 1.0 makes melodies more random, less than 1.0 '
	'makes melodies less random.')
parser.add_argument('--beam_size', default=1)
parser.add_argument('--branch_factor', default=1)
parser.add_argument('--steps_per_iteration', default=1)
args = parser.parse_args()

from esac_utils import *


def possible_options(prev, terms):
	if "_" in prev:
		return [term for term in terms if "_" not in term]
	return terms


def generate_melody(primer, steps_to_generate, terms):
	if steps_to_generate == 0:
		return primer
	sents = []
	current_sent = primer
	with open('single.oracle', 'w') as f:
		for option in possible_options(primer[-1], terms):
			new_sent = current_sent + [option]
			sent = ' '.join(new_sent)
			sents.append(new_sent)
			f.write(sent + '\n')
	os.system('build/nt-parser/get_probability\
	 --cnn-mem 1700 \
	 -x \
	 -T train.oracle \
	 -p single.oracle \
	 -P \
	--lstm_input_dim 128 \
	--hidden_dim 128 \
	-m ntparse_pos_0_2_32_128_16_128-pid8599.params \
	--alpha 0.8 \
	-s 10 > output.txt')
	os.system('utils/cut-corpus.pl 3 output.txt > output.trees')
	os.system('build/nt-parser/nt-parser-gen \
	-x \
	-T train_gen.oracle \
	--clusters cluster_terms.txt \
	--input_dim 256 \
	--lstm_input_dim 256 \
	--hidden_dim 256 \
	-p output.trees \
	-m ntparse_gen_D0.3_2_256_256_16_256-pid30679.params > output.likelihoods')
	os.system('utils/prop.pl 50 10 output.txt output.likelihoods > prop.txt 2> rescored.trees')
	print('Check prop.txt')
	scores = []
	with open('prop.txt', 'r') as f:
		for line in f:
			scores.append(float(line))

	chosen_sent = sents[argmax(scores)]
	print(' '.join(chosen_sent))
	return generate_melody(chosen_sent, steps_to_generate - 1, terms)


if __name__ == "__main__":

	with open('train-terms.txt', 'r') as f:
		terms = set(f.read().split())
	primer_sent = esac_to_sent('1__1_1_  2__1__  4__3__  4__0_')
	start_step = len(primer_sent)
	steps_to_generate = args.num_steps - start_step
	generated = generate_melody(primer_sent, steps_to_generate, terms)
	notesequence = esac_to_notesequence(''.join(generated))
	notesequence_to_midi(notesequence)


