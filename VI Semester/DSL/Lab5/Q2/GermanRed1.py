import sys

lastWord = None
sums = 0

for line in sys.stdin:

	word, count = line.strip().split('\t', 1)
	count = int(count)

	if lastWord == None:
		lastWord = word
		sums = count
		continue

	if word == lastWord:
		sums += count
	else:
		print('%s\t%s' % (lastWord, sums));
		sums = count
		lastWord = word

if lastWord == word:
	print('%s\t%s' % (lastWord, sums));