import sys 

for line in sys.stdin:
	age, count = line.strip().split('\t', 1)
	print('%s\t%s' % (age, count))