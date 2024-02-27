#include<stdio.h>
#include "mpi.h"

void ErrorHandler(int error_code)
{
	if(error_code != MPI_SUCCESS)
	{
		int error_class, len_error_string;
		char error_string[100];
		MPI_Error_class(error_code, &error_class);
		MPI_Error_string(error_code, error_string, &len_error_string);
		printf("Error Class: %d\nError String: %s\n", error_class, error_string);
	}
}

int main(int argc, char *argv[])
{
	int rank, size;
	int error_code;
	float ans;

	error_code = MPI_Init(&argc, &argv);
	ErrorHandler(error_code);
	error_code = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	ErrorHandler(error_code);
	error_code = MPI_Comm_size(MPI_COMM_WORLD, &size);
	ErrorHandler(error_code);

	float val = 1 + ((rank + 0.5) / (size - 1)) * ((rank + 0.5) / (size - 1));
	float final = 4 / (val * (size - 1));

	MPI_Reduce(&final, &ans, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);

	if(rank == 0)
		printf("The value of pi is: %.5f\n", ans);

	MPI_Finalize();

	return 0;
}