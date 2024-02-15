import numpy as np

r1 = int(input("Enter r1: "))
c1 = int(input("Enter c1: "))
r2 = int(input("Enter r2: "))
c2 = int(input("Enter c2: "))

if r1 != c2 or r2 != c1:
	print("Invalid Matrix Dimensions!")
else:
	m1 = np.empty((r1, c1), dtype=int)
	m2 = np.empty((r2, c2), dtype=int)
	res = np.zeros((r1, c2), dtype=int)

	print("Matrix 1:")
	for i in range(r1):
		for j in range(c1):
			m1[i][j] = int(input("Enter number: "))

	print("Matrix 2:")
	for i in range(r2):
		for j in range(c2):
			m2[i][j] = int(input("Enter number: "))

	print("Matrix 1:")
	print(m1)
	print("Matrix 2:")
	print(m2)

	for i in range(r1):
		for j in range(c2):
			for k in range(r2):
				res[i][j] += m1[i][k] * m2[k][j]

	print("Resultant Matrix:")
	print(res)