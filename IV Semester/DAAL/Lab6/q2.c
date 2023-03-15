#include<stdio.h>

int opcount=0;

void Swap(int arr[], int i, int j){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

int Partition(int arr[], int left, int right){

	int pivot=arr[right];
	int i=left-1;

	for(int j=left; j<right; j++)
	{
		opcount++;
		if(arr[j]<pivot)
		{
			i++;
			Swap(arr, i, j);
		}
	}
	Swap(arr, i+1, right);
	return i+1;
}

void QuickSort(int arr[], int left, int right){

	if(left<right)
	{
		int piv=Partition(arr, left, right);
		QuickSort(arr, left, piv-1);
		QuickSort(arr, piv+1, right);
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

	QuickSort(arr, 0, n-1);

	printf("Sorted array: ");
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);

	printf("\nOpcount: %d\n", opcount);

	return 0;
}