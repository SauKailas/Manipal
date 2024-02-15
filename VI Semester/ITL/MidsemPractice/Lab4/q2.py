class TwoSum:

	def __init__(self, arr, target):
		self.arr = arr
		self.target = target

	def findPair(self):
		res = []
		d = {}
		for i in range(len(self.arr)):
			temp = target - self.arr[i]
			if temp in d:
				res.append((i, d[temp]))
			else:
				d[self.arr[i]] = i
		return res


n = int(input("Enter number of elements: "))
nums = []
for i in range(n):
	nums.append(int(input("Enter a number: ")))
target = int(input("Enter the target sum: "))
print("Entered array: ", nums)
print("Entered target: ", target)

obj = TwoSum(nums, target)
res = obj.findPair()

print("Result: ", res)