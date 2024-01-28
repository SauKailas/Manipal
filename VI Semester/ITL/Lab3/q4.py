def sortWords(words):
	for i in range(len(words)-1):
		for j in range(len(words)-i-1):
			if words[j] > words[j+1]:
				temp = words[j]
				words[j] = words[j+1]
				words[j+1] = temp

words = list(input("Enter words: ").split(' '))
print("Original Words: ", words)
sortWords(words)
print("Sorted Words: ", words)
