class ReverseString:

	def __init__(self, s):
		self.s = s
		self.words = s.split(" ")
		self.reverse()

	def reverse(self):
		for i in range(len(self.words)):
			self.words[i] = self.words[i][::-1]
		self.concatenate()

	def concatenate(self):
		res = ''
		for i in range(len(self.words)):
			res += self.words[i] + " "
		print("Resultant String: ", res)


s = str(input("Enter a string: "))
obj = ReverseString(s)