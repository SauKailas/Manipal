class Power:

	def __init__(self, base, power):
		self.base = base
		self.power = power
		print(self.calculate(base, power))

	def calculate(self, base, power):
		if power == 0:
			return 1
		return base * self.calculate(base, power-1)

base = int(input("Enter the base: "))
power = int(input("Enter the power: "))
obj = Power(base, power)
