class Circle:

	def __init__(self):
		self.r = int(input("Enter the radius of the circle: "))
		self.perimeter()

	def perimeter(self):
		self.p = 3.14 * 2 * self.r
		self.area()

	def area(self):
		self.a = 3.14 * self.r * self.r
		self.display()

	def display(self):
		print("Perimeter: ", self.p)
		print("Area: ", self.a)

obj = Circle()