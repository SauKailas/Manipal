fileinput = open(r"GermanCredit.txt", "r")

for line in fileinput:
	data = line.strip().split('\t')

	if len(data) == 3:
		creditability, creditamount, duration = data
		print('{0}\t{1}'.format(creditamount, duration))

