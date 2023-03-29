#include<stdio.h>

int Binary_Search(int arr[], int n, int K){

	int l=0, r=n-1, m;

	while(l<=r)
	{
		m=(l+r)/2;
		if(arr[m]==K)
			return m;
		else if(K<arr[m])
			r=m-1;
		else
			l=m+1;
	}
	return -1;
}

int main()
{
	int n, K;
	printf("Enter the size of the array:\t");
	scanf("%d", &n);

	int arr[n];
	printf("Enter the array elements:\n");
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	printf("Enter the key to search:\t");
	scanf("%d", &K);

	int val=Binary_Search(arr, n, K);

	if(val==-1)
		printf("Element not found!\n");
	else
		printf("Element found at index %d!\n", val);

	return 0;
}