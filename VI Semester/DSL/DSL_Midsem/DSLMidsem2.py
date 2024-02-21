def check(tuples):
	n = len(tuples)
	m = len(tuples[0])
	even = []
	odd = []
	none = []

	for i in range(n):
		even_flag = 1
		odd_flag = 1
		for j in range(m):
			if tuples[i][j] % 2 != 0:
				even_flag = 0
			else:
				odd_flag = 0

		if even_flag == 1:
			even.append(tuples[i])
		elif odd_flag == 1:
			odd.append(tuples[i])
		else:
			none.append(tuples[i])

	print("ANSWER:")
	print("Even Tuples : ", even)
	print("Odd Tuples : ", odd)
	print("None Tuples : ", none)

n = int(input("Enter the number of tuples: "))
m = int(input("Enter the number of elements in each tuple: "))

tuples = []

for i in range(n):
	temp = []
	print("TUPLE", i+1)
	for j in range(m):
		temp.append(int(input("Enter a number: ")))
	tuples.append(tuple(temp))

print("Entered tuples : ", tuples)

check(tuples)
