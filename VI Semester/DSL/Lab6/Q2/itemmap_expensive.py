import sys

file = open("example.txt", 'r')
for line in file:
	words = line.strip().split('\t')
	if len(words) == 6:
		date, time, location, product, cost, payment = words
		print("{0}\t{1}".format(location, cost))
