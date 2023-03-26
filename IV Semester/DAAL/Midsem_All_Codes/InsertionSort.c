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
}

int main()
{
	int n;
	printf("Enter size of array: ");
	scanf("%d", &n);

	int arr[n];
	printf("Enter array elements:\n");
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	Insertion_Sort(arr, n);
	printf("Sorted array: ");
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}