class ValidateStr:

	def __init__(self, s):
		self.s = s
		print("String validity: ", self.validate())

	def validate(self):
		stack = []
		for ele in self.s:
			if ele == '(' or ele == '{' or ele == '[':
				stack.append(ele)
			else:
				tos = stack.pop()
				if tos == '(':
					if ele != ')':
						return False
				elif tos == '[':
					if ele != ']':
						return False
				elif tos == '{':
					if ele != '}':
						return False
		if stack:
			return False
		return True

s = str(input("Enter a string of brackets, parentheses, or braces: "))
obj = ValidateStr(s)