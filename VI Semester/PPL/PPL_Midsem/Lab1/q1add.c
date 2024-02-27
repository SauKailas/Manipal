#include<stdio.h>
#include "mpi.h"

int Reversed(int n)
{
	int temp = n;
	int dig;
	int rev = 0;

	while(temp > 0)
	{
		dig = temp % 10;
		temp /= 10;
		rev = rev * 10 + dig;
	}
	return rev;
}

int main(int argc, char *argv[])
{
	int rank, size;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	int nums[size];

	if(rank == 0)
	{
		printf("Enter %d elements: ", size);
		for(int i=0; i<size; i++)
			scanf("%d", &nums[i]);
	}

	printf("Process %d of total %d processes: Original : %d Reversed : %d!\n", rank, size, nums[rank], Reversed(nums[rank]));

	MPI_Finalize();

	return 0;
}