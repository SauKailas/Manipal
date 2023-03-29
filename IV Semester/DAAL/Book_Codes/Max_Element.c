#include<stdio.h>

int Max_Element(int arr[], int n){
	int max=arr[0];

	for(int i=1; i<n; i++)
		if(arr[i]>max)
			max=arr[i];
	return max;
}

int main()
{
	int n, arr[100];

	printf("Enter the size of the array:\t");
	scanf("%d", &n);

	printf("Enter the elements of the array:\n");
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	printf("The maximum element is %d\n", Max_Element(arr, n));

	return 0;
}