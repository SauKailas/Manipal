n = int(input("Enter the number of elements: "))
x = []
for i in range(n):
	x.append(int(input("Enter number: ")))
print("List: ", x)

evenlist = []
for ele in x:
	if ele % 2 == 0:
		evenlist.append(ele)

for ele in evenlist:
	x.remove(ele)

print("List without even numbers: ", x)