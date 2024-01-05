n = int(input("Enter the number of elements: "))
x = []
for i in range(n):
	x.append(int(input("Enter number: ")))
print("List: ", x)

print("The negative numbers are: ")
for ele in x:
	if ele < 0:
		print(ele)