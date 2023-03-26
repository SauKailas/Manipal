/*
Write a program to sort set of integers using bubble sort. Analyze its time efficiency. 
Obtain the experimental result of order of growth. Plot the result for the best and worst case.

ALGORITHM:
Input: An array A of n orderable elements.
Output: Array A sorted in non-descending order.

for i<-0 to n-2 do
	for j<-0 to n-1 do
		if A[j+1]<A[j] swap A[j+1] and A[j]
*/

#include<stdio.h>

void Bubble_Sort(int A[], int n){
	for(int i=0; i<n-1; i++)
		for(int j=0; j<n-i-1; j++)
			if(A[j+1]<A[j])
			{
				int t=A[j];
				A[j]=A[j+1];
				A[j+1]=t;
			}
}

int main()
{
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);

	int A[n];
	printf("Enter the array elements:\n");
	for(int i=0; i<n; i++)
		scanf("%d", &A[i]);

	Bubble_Sort(A, n);
	printf("\nThe sorted array is: ");
	for(int i=0; i<n; i++)
		printf("%d ", A[i]);
	printf("\n");

	return 0;
}