#include<stdio.h>

void Bubble_Sort(int arr[], int n){

	for(int i=0; i<n-1; i++)
		for(int j=0; j<n-i-1; j++)
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
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

	Bubble_Sort(arr, n);

	printf("The sorted array is:\n");
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}