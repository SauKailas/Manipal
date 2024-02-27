#include<stdio.h>
#include "mpi.h"

int main(int argc, char *argv[])
{
	int rank, size;
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	char str[size], ch, ans[100], buf[100];

	if(rank == 0)
	{
		printf("Enter a word of length %d: ", size);
		scanf("%s", str);

		for(int i=1; i<size; i++)
			MPI_Send(&str[i], 1, MPI_CHAR, i, i, MPI_COMM_WORLD);

		ans[0] = str[0];

		for(int i=1; i<size; i++)
		{
			int temp = i * (i+1) / 2;
			MPI_Recv(&ans[temp], i+1, MPI_CHAR, i, i, MPI_COMM_WORLD, &status);
		}

		printf("Final String: %s\n", ans);
	}
	else
	{
		MPI_Recv(&ch, 1, MPI_CHAR, 0, rank, MPI_COMM_WORLD, &status);
		for(int i=0; i<=rank+1; i++)
		buf[i] = ch;		
		MPI_Send(buf, rank+1, MPI_CHAR, 0, rank, MPI_COMM_WORLD);
	}

	MPI_Finalize();

	return 0;
}