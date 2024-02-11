import sys

# Get inputs from command line
for line in sys.stdin:

	# Create tuples of all words in the input
	L = [(word.strip().lower(), 1) for word in line.strip().split()]

	for word, count in L:
		print('%s\t%s' % (word, count));