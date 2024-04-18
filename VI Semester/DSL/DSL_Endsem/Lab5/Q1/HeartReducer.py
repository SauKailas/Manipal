import sys 

current_age = None
current_count = 0
age = None 

for line in sys.stdin:
	line = line.strip()
	age, count = line.split(',,', 1)

	try:
		count = int(count)
	except ValueError:
		continue

	if current_age == age:
		current_count += count 
	else:
		if current_age:
			print('%s : %s' % (current_age, current_count))
		current_age = age 
		current_count = count

if current_age:
	print('%s : %s' % (current_age, current_count))
