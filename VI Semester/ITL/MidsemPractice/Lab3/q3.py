def BinarySearch(nums, target, left, right):
	if left > right:
		return -1

	mid = (left + right) // 2

	if nums[mid] == target:
		return mid
	elif nums[mid] > target: 
		return BinarySearch(nums, target, left, mid-1)
	else:
		return BinarySearch(nums, target, mid+1, right)


n = int(input("Enter the number of elements: "))
nums = []
for i in range(n):
	nums.append(int(input("Enter a number: ")))
target = int(input("Enter the element to search: "))

nums.sort()
print("Sorted Numbers: ", nums)
print("Target: ", target)

res = BinarySearch(nums, target, 0, len(nums)-1)

if res == -1:
	print("Element NOT found!")
else:
	print("Element FOUND at: ", res)