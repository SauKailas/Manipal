#include<stdio.h>
#include "mpi.h"

float Average(float nums[], int n)
{
	int sum = 0;
	float avg;

	for(int i=0; i<n; i++)
		sum += nums[i];
	avg = sum / n;
	return avg;
}

int main(int argc, char *argv[])
{
	int rank, size;
	int M;
	float arr[100], buf[100];
	float avg, avgs[100];
	float totavg = 0;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0)
	{
		printf("Enter the value of M: ");
		scanf("%d", &M);

		printf("Enter %d elements: ", size*M);
		for(int i=0; i<size*M; i++)
			scanf("%f", &arr[i]);
	}

	MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Scatter(arr, M, MPI_FLOAT, buf, M, MPI_FLOAT, 0, MPI_COMM_WORLD);

	avg = Average(buf, M);

	MPI_Gather(&avg, 1, MPI_FLOAT, avgs, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);

	if(rank == 0)
	{
		for(int i=0; i<size; i++)
		{
			printf("Process %d: %.2f\n", i, avgs[i]);
			totavg += avgs[i];
		}
		totavg /= size;
		printf("Final Average: %.2f\n", totavg);
	}

	MPI_Finalize();

	return 0;
}