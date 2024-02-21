n = int(input("Enter the number of elements: "))
nums = []
for i in range(n):
	nums.append(int(input("Enter a number: ")))

pos = 0
neg = 0

for ele in nums:
	if ele < 0:
		neg += 1
	else:
		pos += 1

print("Positive Numbers: ", pos)
print("Negative Numbers: ", neg)