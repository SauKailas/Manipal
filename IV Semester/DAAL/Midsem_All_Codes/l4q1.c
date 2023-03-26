/*
Write a program for assignment problem by brute-force technique and analyze its time efficiency. 
Obtain the experimental result of order of growth and plot the result.
*/

#include<stdio.h>

int n;
int mat[10][10];
int min_cost=0;
int min_tuple[10];
int jobs_tuple[10];

void Swap(int arr[], int i, int j){
	int t=arr[i];
	arr[i]=arr[j];
	arr[j]=t;
}

void Permutations(int arr[], int n, int l, int r){
	int i;
	if(l==r)
	{
		int sum=0;
		for(int i=0; i<n; i++)
			sum+=mat[i][arr[i]];
		if(sum<min_cost)
		{
			min_cost=sum;
			for(int i=0; i<n; i++)
			{
				jobs_tuple[i]=arr[i];
				min_tuple[i]=mat[i][arr[i]];
			}
		}
	}
	else
	{
		for(int i=l; i<=r; i++)
		{
			Swap(arr, l, i);
			Permutations(arr, n, l+1, r);
			Swap(arr, l, i);
		}
	}
}

int main()
{
	printf("Enter the value of n: ");
	scanf("%d", &n);

	printf("Enter the cost-adjacency matrix:\n");
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &mat[i][j]);

	int idx[10];
	for(int i=0; i<n; i++)
	{
		min_cost+=mat[i][i];
		min_tuple[i]=0;
		idx[i]=i;
	}

	Permutations(idx, n, 0, n-1);

	printf("Minimum sum is: %d\n", min_cost);

	printf("Minimum tuple is:\n");
	for(int i=0; i<n; i++)
		printf("%d ", min_tuple[i]);
	
	printf("\nJobs assigned are:\n");
	for(int i=0; i<n; i++)
		printf("Person %d gets job %d\n", i+1, jobs_tuple[i]+1);
	printf("\n");

	return 0;
}