#include<stdio.h>
#include "mpi.h"

int main(int argc, char *argv[])
{
	int rank, size;
	int mat[3][3], ele;
	int count = 0, finalcount = 0;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0)
	{
		printf("Enter the elements of the 3*3 matrix: ");
		for(int i=0; i<3; i++)
			for(int j=0; j<3; j++)
				scanf("%d", &mat[i][j]);

		printf("Enter the element to search: ");
		scanf("%d", &ele);

		printf("\nENTERED MATRIX:\n");
		for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
				printf("%d ", mat[i][j]);
			printf("\n");
		}
	}

	MPI_Bcast(&ele, 1, MPI_INT, 0, MPI_COMM_WORLD);

	for(int i=0; i<3; i++)
		MPI_Bcast(mat[i], 3, MPI_INT, 0, MPI_COMM_WORLD);

	for(int i=0; i<3; i++)
		if(mat[rank][i] == ele)
			count++;

	MPI_Reduce(&count, &finalcount, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

	if(rank == 0)
		printf("The element was found %d times!\n", finalcount);

	MPI_Finalize();

	return 0;
}