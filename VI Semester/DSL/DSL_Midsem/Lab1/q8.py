n = int(input("Enter number of elements: "))
nums = []
for i in range(n):
	nums.append(int(input("Enter a number: ")))

print("Negative numbers:")
for ele in nums:
	if ele < 0:
		print(ele)