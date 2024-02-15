def findMinimum(nums):
	res = nums[0]
	for i in range(len(nums)):
		if nums[i] < res:
			res = nums[i]
	return res

n = int(input("Enter number of elements: "))
nums = []
for i in range(n):
	nums.append(int(input("Enter a number: ")))

res = findMinimum(nums)
print("Minimum Element: ", res)