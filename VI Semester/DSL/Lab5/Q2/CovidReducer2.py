import sys 

current_max = -1
frequents = []

for line in sys.stdin:
	date, count = line.strip().split('\t', 1)

	try:
		count = int(count)
	except ValueError:
		continue

	if count > current_max:
		current_max = count
		frequents = [date]
	elif count == current_max:
		frequents.append(date)

print("MOST FREQUENT DATES : ")
print("Date\tFrequency")
for date in frequents:
	print('%s\t%s' % (date, current_max))