import sys

current_max = -1
frequents = []

for line in sys.stdin:
	amount, count = line.strip().split('\t', 1)

	try:
		count = int(count)
	except ValueError:
		continue

	if count > current_max:
		current_max	 = count
		frequents = [amount]
	elif count == current_max:
		frequents.append(amount)

print("MOST FREQUENT AMOUNTS : ")
print("Amount\tCount")
for amount in  frequents:
	print('%s\t%s' % (amount, current_max))