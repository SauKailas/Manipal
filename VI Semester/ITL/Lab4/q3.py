class Power:
	def __init__(self, x, n):
		self.x = x
		self.n = n
		print(self.power(x, n))

	def power(self, x, n):
		if n == 0:
			return 1
		return x * self.power(x, n-1)

x = int(input("Enter the base: "))
n = int(input("Enter the power: "))
obj = Power(x, n)