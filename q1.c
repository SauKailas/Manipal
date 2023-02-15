#include<stdio.h>

int opcount=0;

void Bubble_Sort(int arr[], int n){

	for(int i=0; i<n-1; i++)
		for(int j=0; j<n-1-i; j++)
		{
			opcount++;
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	
	printf("The operation count is %d\n", opcount);

	printf("The sorted array is:\n");
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");	
}

int main()
{
	int n;
	printf("Enter length of array:\n");
	scanf("%d", &n);

	int arr[n];

	printf("Enter numbers:\n");
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	Bubble_Sort(arr, n);

	return 0;
}