def MissingValues(tuples):
	n = len(tuples)
	m = len(tuples[0])
	ans = []

	for i in range(n):
		missing = []
		maxval = tuples[i][0]
		for ele in tuples[i]:
			if ele > maxval:
				maxval = ele

		for j in range(0, maxval):
			if j not in tuples[i]:
				missing.append(j)
		ans.append(tuple(missing))

	print("Missing Elements: ")
	print(ans)

n = int(input("Enter the number of tuples: "))
m = int(input("Enter the number elements in each tuple: "))
tuples = []

for i in range(n):
	temp = []
	for j in range(m):
		temp.append(int(input("Enter a number: ")))
	tuples.append(tuple(temp))

print("Entered Tuples: ")
print(tuples)

MissingValues(tuples)