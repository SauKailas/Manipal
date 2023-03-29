EUCLIDS ALGORITHM
//Calculates the GCD of two numbers
//Input: Two non-negative, not both zero integers m, n
//Output: The GCD of m and n
while n>0
	t=m mod n 
	m=n 
	n=t

CONSECUTIVE INTEGER CHECKING
//Calculates the GCD of two numbers
//Input: Two non-negative, not both zero integers m, n
//Output: The GCD of m and n
Step 1: Assign the value of min{m, n} to t 
Step 2: Divide m by t, if remainder is 0 go to Step 3, else go to Step 4
Step 3: Divide n by t, if remainder is 0 return t and STOP, else go to Step 4
Step 4: Reduce t by 1 and go to Step 2

MIDDLE-SCHOOL PROCEDURE
//Calculates the GCD of two numbers
//Input: Two non-negative, not both zero integers m, n
//Output: The GCD of m and n
Step 1: Find all the prime factors of m 
Step 2: Find all the prime factors of n
Step 3: Find the common factors in both expansions of m and n 
Step 4: Multiply the common factors and return the value as GCD

ALGORITHM SIEVE
//Generates list of prime numbers less than a given value
//Input: An integer n>=2
//Output: An array L with all prime numbers less than or equal to n
for p<-2 to n do
	A[p]<-p
for p<-2 to sqrt(n) do 
	if A[p]!=0
		j<-p*p 
		while j<=n do 
			A[j]<-0
			j<-j+p 

i<-0
for p<-2 to p<-n do 
	if A[p]!=0 
		L[i]<-A[p]
		i<-i+1
return L 

SEQUENTIAL SEARCH 1
//Searches a key from an array of elements
//Input: An array of elements A and a key K to search
//Output: Index of the first position where element is found or -1 if not found
i<-0
while i<n and A[i]!=K 
	i<-i+1
if i<n  
	return i 
return -1

SEQUENTIAL SEARCH 2
A[n]<-K
i<-0
while A[i]!=K 
	i<-i+1
if i<n 
	return i
return -1


LARGEST ELEMENT
//Find largest element in a given array
//Input: An array A of n real numbers
//Output: Value of largest element in A
max<-A[0]
for i<-1 to n-1 do 
	if A[i]>max
		max<-A[i]
return max

DISTINCT ELEMENTS
//Determine where all elements in an array are distinct
//Input: An array A of size n of numbers
//Output: True or false
for i<-0 to n-2 do 
	for j<-i+1 to n-1 do 
		if A[i]=A[j] 
			return false 
return true

MATRIX MULTIPLICATION
//Multiply two square matrices
//Input: Two square matrices A and B of size n
//Output: A resultant matrix C
for i<-0 to n-1 do 
	for j<-0 to n-1 do 
		C[i, j]<-0
		for k<-0 to n-1 do 
			C[i, j]<-C[i, j]+A[i, k]*B[k, j]
return C

COUNTING BINARY DIGITS
//Count the number of bits required to represent a number in binary
//Input: A positive decimal integer n
//Output: Number of bits needed to represent n in binary
count<-1
while n>1 do 
	count<-count+1
	n<-floor(n/2)
return count

BINREC
//Counting binary digits using recursion
if n=1
	return 1
return 1+BinRec(floor(n/2))

FACTORIAL
//Find factorial of an integer n
//Input: Positive integer n
//Output: Factorial of n
if(n==0)
	return 1;
return n*Factorial(n-1);

TOWER OF HANOI
void Tower_of_Hanoi(int n, char src, char aux, char dst){

	if(n==1)
	{
		printf("Move %d from %c to %c", n, src, dst);
		return;
	}

	Tower_of_Hanoi(n-1, src, aux, dst);
	print("Move %d from %c to %c", n, src, dst);
	Tower_of_Hanoi(n-1, aux, src, dst);
}

BUBBLE SORT
//Sort an array in non-decreasing order
//Input: An array A of size n
//Output: Array A sorted in ascending order
for i<-0 to n-2 do
	for j<-0 to n-2-i do 
		if A[j+1]<A[j]
			swap A[j+1] and A[j]

SELECTION SORT
//Sort an array in non-decreasing order (number of key swaps is n-1)
//Input: An array A of size n
//Output: Array A sorted in ascending order
for i<-0 to n-2 do
	min=i
	for j<-i+1 to n-1 do 
		if A[j]<A[min]
			min=j
		swap A[i] and A[min]

STRING MATCHING
//Given a string, find a pattern inside it
//Input: An array T of size n and an array P of size m
//Output: Index of first character in T where pattern is found
for i<-0 to n-m do 
	j<-0
	while j<m and T[i+j]=P[j] do 
		j<-j+1
	if j=m
		return i 
return -1

INSERTION SORT (decrease by one)
//Sort an array in non-decreasing order
//Input: An array A of size n
//Output: Array A in ascending order
for i<-1 to n-1 do 
	v<-A[i]
	j<-i-1
	while j>=0 and A[j]>v do 
		A[j+1]<-A[j]
		j<-j-1
	A[j+1]=v 
return A  

BINARY SEARCH
//Input: An array A in ascending order and a key K to find
//Output: Index of element if found, else -1
l<-0
r<-n-1
while l<=r do 
	m<-floor((l+r)/2)
	if K=A[m]
		return m
	else if K<A[m]
		r<-m-1
	else
		l<-m+1
return -1

MERGESORT
//Sorts array A of size n by recursive mergesort
//Input: Array A of size n
//Output: Array A sorted in ascending order
if n>1 
	copy A[0...floor(n/2)-1] to B[0...floor(n/2)-1]
	copyA[floor(n/2)...n-1] to C[0...roof(n/2)-1]
	Mergesort(B)
	Mergesort(C)
	Merge(B, C, A)

MERGE 
//Merges two sorted arrays into one sorted array
//Input: Arrays B and C of size p and q, respectively
//Output: Sorted array A of size p+q-1
i<-0, j<-0, k<-0
while i<p and j<q do 
	if B[i]<=C[j] do
		A[k]<-B[i]
		i<-i+1
	else 
		A[k]<-C[j]
		j<-j+1
	k<-k+1
if i=p do
	copy C[j...q-1] to A[k...p+q-1]
else 
	copy B[i...p-1] to A[k...p+q-1]