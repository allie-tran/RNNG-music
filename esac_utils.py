from nltk import Tree
import mido

pitch_to_midi = {'1': 0, '2': 2, '3': 4, '4': 5, '5': 7, '6': 9, '7': 11}
def get_next_word_end(line, start):
	if start >= len(line):
		return start, False
	while line[start].isspace():
		start += 1
	end = start
	if line[start] in ['_', '^', '.']:
		while end < len(line) and line[end] in ['_', '^','.']:
			end += 1
		return start, end
	if line[end] in ['+', '-']:
		end += 1
	if line[end].isdigit():
		end += 1
	if end < len(line) and line[end] in ['b', '#']:
		end += 1
	return start, end

def esac_to_sent(esac):
	sent = []
	start = 0
	while True:
		start, end = get_next_word_end(esac, start)
		if not end:
			break
		sent.append(esac[start:end])
		start = end
	print(' '.join(sent))

	return sent

def bracket_to_esac(bracket_representation):
	t = ''.join(Tree.fromstring(bracket_representation).leaves())
	return t

def esac_to_notesequence(esac):
	middle_C = 60

	tick = 16
	current_note = -1
	note_sequence = []
	octave = 0
	for i, w in enumerate(esac):
		if w in ['', 'b', '#']:
			continue
		if w == '+':
			octave = 1
		if w ==  '-':
			octave = -1
		if w.isdigit():
			if w == '0':
				current_note = -2
			else:
				current_note = middle_C + pitch_to_midi[w] -1 + 12 * octave
				if i+1 < len(esac):
					if esac[i+1] == 'b':
						current_note -= 1
					if esac[i+1] == '#':
						current_note += 1
			note_sequence.extend([current_note, -1, -1, -1])
			octave = 0
		if w == '_':
			note_sequence.extend([-1] * 4)
		if w == '.':
			note_sequence.extend([-1] * 2)

	return note_sequence

def notesequence_to_midi(notesequence):
	mid = mido.MidiFile()
	mid.ticks_per_beat = 16  # because 1 bar = 4 beat only TODO!
	melody = mid.add_track('Melody')
	previous_note = -1
	for n in notesequence:

		if n == -2:
			if previous_note >= 0:
				melody.append(
					mido.Message(type='note_off', note=int(previous_note), velocity=30, time=0, channel=1))
				previous_note = -1
		elif n >= 0:
			if previous_note >= 0:
				melody.append(
					mido.Message(type='note_off', note=int(previous_note), velocity=30, time=0, channel=1))
			melody.append(mido.Message(type='note_on', note=int(n), velocity=60, time=0, channel=1))
			previous_note = n
		melody.append(mido.Message('control_change', time=1, channel=1))
	mid.save('melody.mid')

if __name__ == '__main__':
	# bracket = '(SONG (MEL (PH (N -5_)) (PH (N 3_) (N 3) (N 3) (N 3_) (N 2) (N 2)) (PH (N 2_.) (N 1) (N 1_))) (MEL (PH (N -5_)) (PH (N 4_) (N 4) (N 4) (N 4) (N 3) (N 5) (N 3)) (PH (N 3_) (N 2_) (N 0_))) (MEL (PH (N -5_)) (PH (N 5_) (N 5) (N 5) (N 5_) (N 4) (N 4)) (PH (N 3__) (N 5) (N 4))) (MEL (PH (N 3) (N 2)) (PH (N 1_) (N 1) (N 1) (N 3) (N 2) (N 2_)) (PH (N 1__))) (MEL (PH (N 2_) (N 4_)) (PH (N 3_) (N 3) (N 3) (N 5) (N 4) (N 3) (N 2)) (PH (N 1__) (N 0_))))'
	# esac = bracket_to_esac(bracket)
	# print(esac)
	# notesequence = esac_to_notesequence(esac)
	# notesequence_to_midi(notesequence)

	esac = """4__5
    0_4_  1__."""
	print(esac)
	esac_to_sent(esac)