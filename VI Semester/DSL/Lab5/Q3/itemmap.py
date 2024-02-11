fileinput = open(r"example.txt", "r")

for line in fileinput:
	data = line.strip().split('\t')

	if len(data) == 6:
		date, time, location, item, cost, payment = data
		print('{0}\t{1}'.format(location, cost))

