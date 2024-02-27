#include<stdio.h>
#include<stdlib.h>
#include "mpi.h"

void replaceNumbers(int arr[0], int n)
{
	for(int i=0; i<n; i++)
	{
		if(arr[i] % 2 == 0)
			arr[i] = 1;
		else
			arr[i] = 0;
	}
}

int main(int argc, char *argv[])
{
	int rank, size;
	int N, arr[100], chunksize, buf[100], ans[100];
	int even_count = 0, odd_count = 0;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0)
	{
		printf("Enter the number of elements: ");
		scanf("%d", &N);

		if(N % size != 0)
		{
			printf("Number of elements not divisible by %d!\n", size);
			exit(0);
		}

		printf("Enter the elements: ");
		for(int i=0; i<N; i++)
			scanf("%d", &arr[i]);

		chunksize = N / size;
	}

	MPI_Bcast(&chunksize, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Scatter(arr, chunksize, MPI_INT, buf, chunksize, MPI_INT, 0, MPI_COMM_WORLD);

	replaceNumbers(buf, chunksize);

	printf("Process %d: ", rank);
	for(int i=0; i<chunksize; i++)
		printf("%d ", buf[i]);
	printf("\n");

	MPI_Gather(buf, chunksize, MPI_INT, ans, chunksize, MPI_INT, 0, MPI_COMM_WORLD);

	if(rank == 0)
	{
		printf("Resultant Array: ");
		for(int i=0; i<N; i++)
		{
			printf("%d ", ans[i]);
			if(ans[i] == 1)
				even_count++;
			else
				odd_count++;
		}
		printf("\nEven Count: %d\n", even_count);
		printf("Odd Count: %d\n", odd_count);
	}

	MPI_Finalize();

	return 0;
}