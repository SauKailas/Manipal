import sys

current_max = 0
frequents = []

for line in sys.stdin:
	age, count = line.strip().split('\t', 1)

	try:
		count = int(count)
	except ValueError:
		continue

	if count > current_max:
		current_max = count
		frequents = [age]
	elif count == current_max:
		frequents.append(age)

print("MOST FREQUENT AGES : ")
print("Age\tCount")
for age in frequents:
	print('%s\t%s' % (age, current_max))