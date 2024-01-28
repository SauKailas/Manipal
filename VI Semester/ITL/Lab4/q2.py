class TargetSum:
	def __init__(self, arr, target):
		self.arr = arr;
		self.target = target;

	def findPair(self):
		ans = []
		dictionary = {}
		for i in range(len(self.arr)):
			temp = self.target - self.arr[i];
			if temp in dictionary:
				ans.append((i, dictionary[temp]))
			else:
				dictionary[self.arr[i]] = i
		return ans

array = [10, 20, 10, 40, 50, 60, 70]
target = 50
obj = TargetSum(array, target)
print(obj.findPair());