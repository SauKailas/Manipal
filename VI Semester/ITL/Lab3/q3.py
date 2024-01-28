def binarySearch(arr, left, right, ele):
	if left <= right:
		mid = left + (right - left) // 2
		if arr[mid] == ele:
			return mid
		elif ele < arr[mid]:
			return binarySearch(arr, left, mid-1, ele)
		else:
			return binarySearch(arr, mid+1, right, ele)
	else:
		return -1

arr = [1, 2, 3, 4, 5]
ele = 5

res = binarySearch(arr, 0, len(arr)-1, ele)
if res == -1:
	print(ele, " not found!")
else:
	print(ele, " found at index: ", res)
