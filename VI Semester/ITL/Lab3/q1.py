n1 = float(input("Enter a number: "))
n2 = float(input("Enter a number: "))
op = input("Enter the operator: ")

if op == '+':
	ans = n1 + n2
elif op == '-':
	ans = n1 - n2
elif op == '*':
	ans = n1 * n2
else:
	ans = n1 / n2

print(ans)