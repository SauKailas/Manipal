t = (12, 7, 38, 56, 78)
even = []

for ele in t:
	if ele % 2 == 0:
		even.append(ele)

print("The even numbers are: ", tuple(even))