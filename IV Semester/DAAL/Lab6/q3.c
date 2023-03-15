#include<stdio.h>

int opcount=0;

void Merge(int A[], int B[], int C[], int nA, int nB, int nC){

	int b=0, c=0, a=0;

	while(b<nB && c<nC)
	{
		opcount++;
		if(B[b]<C[c])
			A[a++]=B[b++];
		else
			A[a++]=C[c++];
	}

	if(b==nB)
	{
		for(int m=c; m<nC; m++)
		{
			opcount++;
			A[a++]=C[m];
		}
	}
	else
	{
		for(int m=b; m<nB; m++)
		{
			opcount++;
			A[a++]=B[m];
		}
	}
}

void MergeSort(int A[], int n){

	if(n>1)
	{
		int B[n/2], C[n/2];
		int nB=0, nC=0;

		for(int i=0; i<n/2; i++)
			B[nB++]=A[i];

		for(int i=n/2; i<n; i++)
			C[nC++]=A[i];

		MergeSort(B, nB);
		MergeSort(C, nC);
		Merge(A, B, C, n, nB, nC);
	}
}

int main()
{
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);

	int arr[n];
	printf("Enter the elements of the array:\n");
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	MergeSort(arr, n);

	printf("Sorted array: ");
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);

	printf("\nOpcount: %d\n", opcount);

	return 0;
}