#include<stdio.h>

void Insertion_Sort(int A[], int n){

	for(int i=1; i<n; i++)
	{
		int v=A[i];
		int j=i-1;

		while(j>=0 && A[j]>v)
		{
			A[j+1]=A[j];
			j--;
		}

		A[j+1]=v;
	}

	printf("The sorted array is:\n");
	for(int i=0; i<n; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main()
{
	int n;
	printf("Enter the size of the array:\t");
	scanf("%d", &n);

	int arr[n];
	printf("Enter the elements of the array:\n");
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	Insertion_Sort(arr, n);
	return 0;
}