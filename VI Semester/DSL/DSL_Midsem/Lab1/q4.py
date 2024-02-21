n1 = int(input("Enter n1: "))
n2 = int(input("Enter n2: "))
n3 = int(input("Enter n3: "))

if n1 > n2:
	if n1 > n3:
		largest = n1
	else:
		largest = n3
else:
	if n2 > n3:
		largest = n2
	else:
		largest = n3

print("The largest number is: ", largest)