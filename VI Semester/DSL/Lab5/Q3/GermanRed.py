import sys

credit_count = 0
total_credit = 0

for line in sys.stdin:
	data = line.strip().split('\t')
	
	if len(data) != 2:
		continue

	current_key, current_value = data
	credit_count += 1
	total_credit += float(current_value)

print("Total Transactions\tTotal Credit")
print(credit_count, '\t\t\t', total_credit)