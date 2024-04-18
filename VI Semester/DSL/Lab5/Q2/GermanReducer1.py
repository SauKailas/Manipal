import sys 

current_amount = None
current_count = 0
amount = None

for line in sys.stdin:
	line = line.strip()

	amount, count = line.split('\t', 1)

	try:
		count = int(count)
	except ValueError:
		continue

	if current_amount == amount:
		current_count += count
	else:
		if current_amount:
			print('%s\t%s' % (current_amount, current_count))
		current_amount = amount
		current_count = count 

if current_amount == amount:
	print('%s\t%s' % (current_amount, current_count))