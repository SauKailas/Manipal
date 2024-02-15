class String: 

	def __init__(self):
		self.string = ''

	def getString(self):
		self.string = str(input("Enter a string: "))
		self.printString()

	def printString(self):
		print("Uppercase string is: ", self.string.upper())

obj = String()
obj.getString()