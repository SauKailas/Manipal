/*
Sort given set of integers using Merge sort and analyze its efficiency. 
Obtain the experimental result of order of growth and plot the result.
*/

#include<stdio.h>

void Merge(int A[], int B[], int C[], int nA, int nB, int nC){
	int i=0, j=0, k=0;

	while(i<nB && j<nC)
	{
		if(B[i]<C[j])
			A[k++]=B[i++];
		else
			A[k++]=C[j++];
	}

	if(i==nB)
	{
		for(int m=j; m<nC; m++)	
			A[k++]=C[m];
	}
	else
	{
		for(int m=i; m<nB; m++)
			A[k++]=B[m];
	}
}

void Mergesort(int A[], int n){
	int B[20], C[20], nB=0, nC=0;

	if(n>1)
	{
		for(int i=0; i<n/2; i++)
			B[nB++]=A[i];
		for(int i=n/2; i<n; i++)
			C[nC++]=A[i];

		Mergesort(B, nB);
		Mergesort(C, nC);
		Merge(A, B, C, n, nB, nC);
	}
}

int main()
{
	int n;
	printf("Enter the size of the array: ");
	scanf("%d", &n);

	int arr[n];
	printf("Enter the array elements:\n");
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	Mergesort(arr, n);
	printf("Sorted array: ");
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
