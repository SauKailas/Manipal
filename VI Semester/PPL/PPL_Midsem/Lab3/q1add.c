#include<stdio.h>
#include "mpi.h"

int Power(int base, int power)
{
	if(power == 1)
		return 1;
	return base * Power(base, power-1);
}

void findPower(int arr[], int n, int power)
{
	for(int i=0; i<n; i++)
		arr[i] = Power(arr[i], power);
}

int main(int argc, char *argv[])
{
	int rank, size;
	int M, arr[100], buf[100], ans[100];

	MPI_Init(&argc, &argv);c
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0)
	{
		printf("Enter the value of M: ");
		scanf("%d", &M);

		printf("Enter %d elements: ", M*size);
		for(int i=0; i<M*size; i++)
			scanf("%d", &arr[i]);
	}

	MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Scatter(arr, M, MPI_INT, buf, M, MPI_INT, 0, MPI_COMM_WORLD);

	findPower(buf, M, rank+3);
	printf("Process %d: ", rank);
	for(int i=0; i<M; i++)
		printf("%d ", buf[i]);
	printf("\n");

	MPI_Gather(buf, M, MPI_INT, ans, M, MPI_INT, 0, MPI_COMM_WORLD);

	if(rank == 0)
	{
		printf("Resultant Array: ");
		for(int i=0; i<M*size; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}

	MPI_Finalize();

	return 0;
}