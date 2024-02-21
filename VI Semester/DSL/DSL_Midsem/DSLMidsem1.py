def isPalindrome(num):
	temp = num
	rev = 0
	while temp != 0:
		dig = temp % 10
		temp = temp // 10
		rev = rev * 10 + dig
	if rev == num:
		return True
	return False

n = int(input("Enter the number of tuples: "))
m = int(input("Enter the number of elements in a tuple: "))

nums = []
for i in range(n):
	temp = []
	print("Enter the elements of tuple ", i+1)
	for j in range(m):
		temp.append(int(input("Enter a number: ")))
	nums.append(tuple(temp))

print("The array of tuples is: ")
print(nums)

print("The palindrome numbers are: ")
for i in range(n):
	for j in range(m):
		if isPalindrome(nums[i][j]):
			print(nums[i][j])