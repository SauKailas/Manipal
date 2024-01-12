x = []
n = int(input("Enter the number of elements: "))
for i in range(n):
	x.append(int(input("Enter a number: ")))

print("Negative Numbers: ")
for ele in x:
	if ele < 0:
		print(ele)
