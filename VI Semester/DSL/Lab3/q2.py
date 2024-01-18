import numpy as np

rows = int(input("Enter number of rows: "))
cols = int(input("Enter number of columns: "))

matrix = np.empty((rows, cols), dtype=int)

for i in range(rows):
	for j in range(cols):
		matrix[i, j] = int(input("Enter element: "))

print("Entered matrix:")
print(matrix)

row_sum = np.sum(matrix, axis=1)
col_sum = np.sum(matrix, axis=0)

print("Row Sums: ")
for i in range(rows):
	print("Row ", i, " sum is ", row_sum[i])
print("Column Sums: ")
for i in range(cols):
	print("Column ", i, " sum is ", col_sum[i])