import sys 

curr_chol = 0
curr_age = None

for line in sys.stdin:
	age, chol = line.strip().split('\t')

	try:
		age = int(age)
		chol = float(chol)
	except ValueError:
		continue

	if age == curr_age:
		if chol > curr_chol:
			curr_chol = chol 
	else:
		if curr_age:
			print('%s\t%s' % (curr_age, curr_chol))
		curr_age = age 
		curr_chol = chol

if curr_age == age:
	print('%s\t%s' % (curr_age, curr_chol))