#include<stdio.h>

void Selection_Sort(int arr[], int n){

	for(int i=0; i<n-1; i++)
	{
		int min=i;
		for(int j=i+1; j<n; j++)
			if(arr[j]<arr[min])
				min=j;

		int temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
	}
}

int main()
{
	int n, arr[100];

	printf("Enter the size of the array:\t");
	scanf("%d", &n);

	printf("Enter the elements of the array:\n");
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	Selection_Sort(arr, n);

	printf("The sorted list is:\n");
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}