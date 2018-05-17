from collections import Counter

def isnote(s):
    return any(i.isdigit() for i in s)

def getnote(s):
	for i in s:
		if i.isdigit():
			return int(i)

def get_sharp_or_flat(s):
	if s[-1] == 'b':
		return 1
	if s[-1] == '#':
		return 2
	return 0

def get_cluster(s):
	if "_" in s or s == 'UNK':
		return 0
	if isnote(s):
		return getnote(s) + get_sharp_or_flat(s) * 7


with open('train-terms.txt', 'r') as f:
	terms = set(f.read().split())

with open('cluster_terms.txt', 'w') as f:
	for term in terms:
		cluster = get_cluster(term)
		f.write('{0:08b}'.format(cluster))
		f.write('\t {term} \t {cluster}\n'.format(term=term, cluster=cluster))






