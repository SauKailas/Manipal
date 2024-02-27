#include<stdio.h>
#include "mpi.h"

int main(int argc, char *argv[])
{
	int rank, size;
	float n1, n2;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0)
	{
		printf("Enter number 1: ");
		scanf("%f", &n1);

		printf("Enter number 2: ");
		scanf("%f", &n2);
	}
	else
	{
		switch(rank)
		{
			case 1:
				printf("Process %d of total %d processes: %.2f + %.2f = %.3f!\n", rank, size, n1, n2, n1+n2);
				break;
			case 2:
				printf("Process %d of total %d processes: %.2f - %.2f = %.3f!\n", rank, size, n1, n2, n1+n2);
				break;
			case 3:
				printf("Process %d of total %d processes: %.2f * %.2f = %.3f!\n", rank, size, n1, n2, n1+n2);
				break;
			case 4:
				printf("Process %d of total %d processes: %.2f / %.2f = %.3f!\n", rank, size, n1, n2, n1+n2);
				break;
		}	
	}

	MPI_Finalize();

	return 0;
}