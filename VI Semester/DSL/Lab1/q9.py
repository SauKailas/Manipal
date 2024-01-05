n = int(input("Enter the number of elements: "))
x = []
for i in range(n):
	x.append(int(input("Enter number: ")))
print("List: ", x)

even = 0
odd = 0

for ele in x:
	if ele % 2 == 0:
		even += 1
	else:
		odd += 1

print("Count of even numbers: ", even)
print("Count of odd numbers: ", odd)