#include<stdio.h>
#include "mpi.h"

void ErrorHandler(int error_code)
{
	if(error_code != MPI_SUCCESS)
	{
		int len_error_string, error_class;
		char error_string[100];
		MPI_Error_class(error_code, &error_class);
		MPI_Error_string(error_code, error_string, &len_error_string);
		printf("Error Class: %d\nError String: %s\n", error_class, error_string);
	}
}

int main(int argc, char *argv[])
{
	int rank, size;
	int error_code, fact = 1, ans;

	MPI_Init(&argc, &argv);
	error_code = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	ErrorHandler(error_code);
	error_code = MPI_Comm_size(MPI_COMM_WORLD, &size);
	ErrorHandler(error_code);

	MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);

	for(int i=1; i<=rank; i++)
		fact *= i;

	error_code = MPI_Scan(&fact, &ans, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
	ErrorHandler(error_code);

	printf("Process %d Partial Sum: %d\n", rank, ans);

	MPI_Finalize();

	return 0;
}