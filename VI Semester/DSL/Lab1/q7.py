x = (12, 7, 38, 56, 78)
y = []
for ele in x:
	if ele % 2 == 0:
		y.append(ele)
print(tuple(y))