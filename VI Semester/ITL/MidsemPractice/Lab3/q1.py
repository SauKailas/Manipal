n1 = int(input("Enter a number: "))
n2 = int(input("Enter a number: "))
op = str(input("Enter the operator: "))

if op == '+':
	res = n1 + n2
elif op == '-':
	res = n1 - n2
elif op == '*':
	res = n1 * n2
elif op == '/':
	res = n1 / n2
else:
	res = "Invalid Operator!"

print("Result: ", res)