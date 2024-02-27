#include<stdio.h>
#include "mpi.h"

int main(int argc, char *argv[])
{
	int rank, size;
	int mat[5][5], ans[5][5], temp[5], buf[5];

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0)
	{
		printf("Enter the elements of the 5*5 matrix: ");
		for(int i=0; i<5; i++)
			for(int j=0; j<5; j++)
				scanf("%d", &mat[i][j]);
	}

	for(int i=0; i<5; i++)
		MPI_Scatter(&mat[i], 1, MPI_INT, &temp[i], 1, MPI_INT, 0, MPI_COMM_WORLD);

	int max = temp[0];
	int min = temp[0];

	for(int i=0; i<5; i++)
	{
		if(temp[i] < min)
			min = temp[i];
		if(temp[i] > max)
			max = temp[i];
	}

	buf[rank] = 0;

	for(int i=0; i<rank; i++)
		buf[i] = max;
	for(int i=rank+1; i<5; i++)
		buf[i] = min;

	MPI_Gather(buf, 5, MPI_INT, ans, 5, MPI_INT, 0, MPI_COMM_WORLD);

	if(rank == 0)
	{
		printf("FINAL MATRIX:\n");
		for(int i=0; i<5; i++)
		{
			for(int j=0; j<5; j++)
				printf("%d ", ans[i][j]);
			printf("\n");
		}
	}

	MPI_Finalize();

	return 0;
}