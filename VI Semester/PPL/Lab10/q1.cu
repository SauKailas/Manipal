#include<stdio.h>
#include<stdlib.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

__global__ void SpVM_CSR(int num_rows, int *data, int *col_index, int *row_ptr, int *X, int *Y)
{
	int row = blockIdx.x * blockDim.x + threadIdx.x;

	if(row < num_rows)
	{
		int dot = 0;
		int row_start = row_ptr[row];
		int row_end = row_ptr[row+1];
		for(int elem = row_start; elem < row_end; elem++)
			dot += data[elem] * X[col_index[elem]];
		Y[row] = dot;
	}
}

int main()
{
	int r, c;

	printf("Enter the number of rows: ");
	scanf("%d", &r);
	printf("Enter the number of columns: ");
	scanf("%d", &c);

	int **A = (int**)malloc(r * sizeof(int*));
	for(int i=0; i<r; i++)
		A[i] = (int*)malloc(c * sizeof(int));

	printf("Enter the matrix elements:\n");
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			scanf("%d", &A[i][j]);

	int *X = (int*)malloc(c * sizeof(int));
	int *Y = (int*)malloc(r * sizeof(int));

	printf("Enter the elements of vector X: ");
	for(int i=0; i<c; i++)
		scanf("%d", &X[i]);

	int data[20], col_index[20], row_ptr[20];
	row_ptr[0] = 0;
	int count = 0;

	for(int i=0; i<r; i++)
	{
		int c = 0;
		for(int j=0; j<c; j++)
		{
			if(A[i][j] != 0)
			{
				c++;
				data[count] = A[i][j];
				col_index[count] = j;
				count++;
			}
		}
		row_ptr[i+1] = row_ptr[i] + c;
	}

	int *d_data, *d_col_index, *d_row_ptr, *d_X, *d_Y;
	cudaMalloc((void**)&d_data, count * sizeof(int));
	cudaMalloc((void**)&d_col_index, count * sizeof(int));
	cudaMalloc((void**)&d_row_ptr, (r + 1) * sizeof(int));
	cudaMalloc((void**)&d_X, c * sizeof(int));
	cudaMalloc((void**)&d_Y, r * sizeof(int));

	cudaMemcpy(d_data, data, count * sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(d_col_index, col_index, count * sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(d_row_ptr, row_ptr, (r + 1) * sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(d_X, X, c * sizeof(int), cudaMemcpyHostToDevice);

	SpVM_CSR<<<1, r>>>(r, d_data, d_col_index, d_row_ptr, d_X, d_Y);

	cudaMemcpy(Y, d_Y, r * sizeof(int), cudaMemcpyDeviceToHost);

	printf("Resultant Vector Y: ");
	for(int i=0; i<r; i++)
		printf("%d ", Y[i]);
	printf("\n");

	cudaFree(d_data);
	cudaFree(d_col_index);
	cudaFree(d_row_ptr);
	cudaFree(d_X);
	cudaFree(d_Y);

	return 0;
}