file = open(r"Datasets/GermanCredit.txt", "r")

for line in file:
	data = line.strip().split('\t')
	
	if len(data) == 3:
		creditability, amount, duration = data
		print('%s\t%s\t%s' % (creditability, amount, duration))