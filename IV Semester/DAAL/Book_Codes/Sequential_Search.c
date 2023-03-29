#include<stdio.h>

int Sequential_Search(int arr[], int n, int key){

	arr[n]=key;
	int i=0;
	while(arr[i]!=key)
		i++;
	if(i<n)
		return i;
	return -1;
}

int main()
{
	int arr[100], n, key;

	printf("Enter the size of the array:\t");
	scanf("%d", &n);

	printf("Enter the elements of the array:\n");
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	printf("Enter the key:\t");
	scanf("%d", &key);

	int val=Sequential_Search(arr, n, key);

	if(val>=0)
		printf("Key found at index %d!\n", val);
	else
		printf("Key not found!\n");

	return 0;
}