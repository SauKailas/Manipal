import sys

curr_amount = 0
curr_duration = None

print('Duration\tMax. Credit Amount')

for line in sys.stdin:
	duration, amount = line.strip().split('\t')

	try:
		duration = int(duration)
		amount = float(amount)
	except ValueError:
		continue

	if duration == curr_duration:
		if amount > curr_amount:
			curr_amount = amount 
	else:
		if curr_duration:
			print('%s\t%s' % (curr_duration, curr_amount))
		curr_amount = amount
		curr_duration = duration

if curr_duration:
	print('%s\t%s' % (curr_duration, curr_amount))
