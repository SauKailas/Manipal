#include<stdio.h>

int Unique_Elements(int arr[], int n){

	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(arr[i]==arr[j])
				return 0;
	return 1;		
}

int main()
{
	int n, arr[100];

	printf("Enter the size of the array:\t");
	scanf("%d", &n);

	printf("Enter the elements of the array:\n");
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	if(Unique_Elements(arr, n))
		printf("Array HAS unique elements!\n");
	else
		printf("Array does NOT have unique elements!\n");

	return 0;
}