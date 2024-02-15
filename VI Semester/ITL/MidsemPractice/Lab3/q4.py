def sortWords(words):
	for i in range(len(words)-1):
		for j in range(len(words)-i-1):
			if words[j] > words[j+1]:
				temp = words[j]
				words[j] = words[j+1]
				words[j+1] = temp

n = int(input("Enter the number of words: "))
words = []
for i in range(n):
	words.append(str(input("Enter a word: ")))
print("Entered Words: ", words)

sortWords(words)
print("Sorted Words:")
print(words)