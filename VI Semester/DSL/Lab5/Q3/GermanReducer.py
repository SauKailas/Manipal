import sys

total = 0
count = 0

for line in sys.stdin:
	creditability, amount, duration = line.strip().split('\t')

	try:
		amount = float(amount)
	except ValueError:
		continue

	total += amount
	count += 1

print("Total Number Of Transactions : ", count)
print("Total Credit : ", total)