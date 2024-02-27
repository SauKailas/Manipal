#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "mpi.h"

int main(int argc, char *argv[])
{
	int rank, size;
	char s1[100], s2[100], buf[2], ans[100];

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0)
	{
		printf("Enter string 1: ");
		scanf("%s", s1);

		printf("Enter string 2: ");
		scanf("%s", s2);

		if(strlen(s1) != size || strlen(s2) != size)
		{
			printf("String lengths are not compatible!\n");
			exit(1);
		}	
	}

	MPI_Scatter(s1, 1, MPI_CHAR, &buf[0], 1, MPI_CHAR, 0, MPI_COMM_WORLD);
	MPI_Scatter(s2, 1, MPI_CHAR, &buf[1], 1, MPI_CHAR, 0, MPI_COMM_WORLD);
	MPI_Gather(buf, 2, MPI_CHAR, ans, 2, MPI_CHAR, 0, MPI_COMM_WORLD);

	if(rank == 0)
		printf("Final String: %s\n", ans);

	MPI_Finalize();

	return 0;
}