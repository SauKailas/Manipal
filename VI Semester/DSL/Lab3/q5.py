import numpy as np  

rows = int(input("Enter number of rows: "))
cols = int(input("Enter number of columns: "))

matrix1 = np.empty((rows, cols), dtype=int)
matrix2 = np.empty((rows, cols), dtype=int)

print("MATRIX 1:")
for i in range(rows):
	for j in range(cols):
		matrix1[i, j] = int(input("Enter element: "))

print("MATRIX 2:")
for i in range(rows):
	for j in range(cols):
		matrix2[i, j] = int(input("Enter element: "))

print("Matrix 1:")
print(matrix1)
print("Matrix 2:")
print(matrix2)

res = matrix1 + matrix2
print("Sum:")
print(res)
