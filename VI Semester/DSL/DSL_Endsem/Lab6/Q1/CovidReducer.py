import sys 
from itertools import groupby
from operator import itemgetter

def read_mapper_output(file, separator = '\t'):
	for line in file:
		yield line.strip().split(separator, 1)

separator = '\t'
data = read_mapper_output(sys.stdin, separator = separator)
for current_word, group in groupby(data, itemgetter(0)):
	total_count = 0
	for word, count in group:
		try:
			count = int(count)
		except ValueError:
			continue
		total_count += count
	print('%s%s%s' % (current_word, separator, total_count))

