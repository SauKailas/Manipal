class String:
	def __init__(self):
		self.word = ''

	def get_String(self):
		self.word = str(input("Enter a string: "))
		self.print_String()

	def print_String(self):
		print("Uppercase string is: ", self.word.upper())

obj = String()
obj.get_String()