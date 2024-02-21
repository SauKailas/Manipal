n = int(input("Enter the number of elements: "))
nums = []
for i in range(n):
	nums.append(int(input("Enter a number: ")))

even = []
for ele in nums:
	if ele % 2 == 0:
		even.append(ele)

for ele in even:
	nums.remove(ele)

print("List without even elements: ", nums)