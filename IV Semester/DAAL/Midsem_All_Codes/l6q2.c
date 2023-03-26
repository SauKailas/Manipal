/*
Sort given set of integers using Quick sort and analyze its efficiency. 
Obtain the experimental result of order of growth and plot the result.
*/

#include<stdio.h>

void Swap(int arr[], int i, int j){
	int t=arr[i];
	arr[i]=arr[j];
	arr[j]=t;
}

int Partition(int arr[], int l, int r){
	int pivot=arr[r];
	int i=l-1;

	for(int j=l; j<r; j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			Swap(arr, i, j);
		}
	}
	Swap(arr, i+1, r);
	return i+1;
}

void Quicksort(int arr[], int l, int r){
	if(l<r)
	{
		int p=Partition(arr, l, r);
		Quicksort(arr, l, p-1);
		Quicksort(arr, p+1, r);
	}
}

int main()
{
	int n;
	printf("Enter size of the array: ");
	scanf("%d", &n);

	int arr[n];
	printf("Enter the array elements:\n");
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	Quicksort(arr, 0, n-1);
	printf("Sorted array: ");
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}


