#include<stdio.h>
#include "mpi.h"

int main(int argc, char *argv[])
{
	int rank, size;
	char ch, buf[100];

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	char str[size], ans[100];

	if(rank == 0)
	{
		printf("Enter a string of length %d: ", size);
		scanf("%s", str);
	}

	MPI_Scatter(str, 1, MPI_CHAR, &ch, 1, MPI_CHAR, 0, MPI_COMM_WORLD);

	for(int i=0; i<=rank; i++)
		buf[i] = ch;

	printf("Process %d: %s\n", rank, buf);

	MPI_Send(buf, rank, MPI_CHAR, 0, rank, MPI_COMM_WORLD);

	if(rank == 0)
		printf("The final string is: %s\n", ans);

	MPI_Finalize();

	return 0;
}