import sys

mostFreq = []
currentMax = -1

for line in sys.stdin:

	word, count = line.strip().split('\t', 1)
	count = int(count)

	if count > currentMax:
		currentMax = count
		mostFreq = [word]
	elif count == currentMax:
		mostFreq.append(word)

print("MOST FREQUENT WORD")
print("Word\tFrequency")
for word in mostFreq:
	print('%s\t%s' % (word, currentMax));