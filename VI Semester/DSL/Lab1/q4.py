n1 = int(input("Enter n1: "))
n2 = int(input("Enter n2: "))
n3 = int(input("Enter n3: "))

if n1>n2:
	if n1>n3:
		greatest = n1
	else:
		greatest = n3
elif n2>n3:
	greatest = n2
else:
	greatest = n3

print("The greatest number is: ", greatest)