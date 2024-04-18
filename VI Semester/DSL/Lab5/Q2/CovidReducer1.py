import sys 

current_date = None
current_count = 0
date = None 

for line in sys.stdin:
	line = line.strip()
	date, count = line.split('\t', 1)

	try:
		count = int(count)
	except ValueError:
		continue

	if current_date == date:
		current_count += count 
	else:
		if current_date:
			print('%s\t%s' % (current_date, current_count))
		current_date = date 
		current_count = count 

if current_date == date:
	print('%s\t%s' % (current_date, current_count))