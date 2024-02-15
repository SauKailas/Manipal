infile = open("Input.txt", "r")
outfile = open("Output.txt", "w+")

for line in infile:
	outfile.write(line[::-1])
print("Done!")