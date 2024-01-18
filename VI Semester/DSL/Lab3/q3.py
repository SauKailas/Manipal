import numpy as np

nums = [1.2, 2.3, 3.4, 4.5, 5.6]
array = np.array(nums, dtype=float)
print("a) Array from List of Float: ")
print(array)

t = (1, 2, 3, 4, 5)
array = np.array(t)
print("b) Array from Tuple: ")
print(array)

matrix = np.zeros((3,4))
print("c) Matrix of Zeros: ")
print(matrix)

array = np.arange(0, 21, 5)
print("d) Array with Gap 5: ")
print(array)

matrix = matrix.reshape((2, 2, 3))
print("e) Reshape matrix into 2*2*3: ")
print(matrix)

rows = int(input("Enter number of rows: "))
cols = int(input("Enter number of columns: "))
matrix = np.empty((rows, cols), dtype=int)
for i in range(rows):
	for j in range(cols):
		matrix[i, j] = int(input("Enter element: "))

print("Entered matrix:")
print(matrix)

row_max = np.max(matrix, axis=1)
row_min = np.min(matrix, axis=1)
print("Row Maximums: ", row_max)
print("Row Minimums: ", row_min)

col_max = np.max(matrix, axis=0)
col_min = np.min(matrix, axis=0)
print("Column Maximums: ", col_max)
print("Column Minimums: ", col_min)
