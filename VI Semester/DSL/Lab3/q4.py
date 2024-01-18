import numpy as np  

rows = int(input("Enter number of rows: "))
cols = int(input("Enter number of columns: "))
matrix = np.empty((rows, cols), dtype=int)

for i in range(rows):
	for j in range(cols):
		matrix[i, j] = int(input("Enter element: "))

print("Entered Matrix:")
print(matrix)

transpose_matrix = np.transpose(matrix)

print("Transposed Matrix: ")
print(transpose_matrix)