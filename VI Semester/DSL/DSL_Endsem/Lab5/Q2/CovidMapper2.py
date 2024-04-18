import sys 

for line in sys.stdin:
	date, count = line.strip().split('\t', 1)

	try:
		count = int(count)
	except ValueError:
		continue

	print('%s\t%s' % (date, count))