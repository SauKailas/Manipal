def BubbleSort(nums):
	for i in range(len(nums)-1):
		for j in range(len(nums)-i-1):
			if nums[j] > nums[j+1]:
				temp = nums[j]
				nums[j] = nums[j+1]
				nums[j+1] = temp

n = int(input("Enter number of elements: "))
nums = []
for i in range(n):
	nums.append(int(input("Enter a number: ")))
print("Entered List: ", nums)

BubbleSort(nums)
print("Sorted List: ", nums)