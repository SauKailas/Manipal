#include<stdio.h>
#include<stdlib.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

__global__ void ele_add(int *M1, int *M2, int *res)
{
	int tid = threadIdx.x;
	res[tid] = M1[tid] + M2[tid];
}

int main()
{
	int r, c;

	printf("Enter the number of rows: ");
	scanf("%d", &r);
	printf("Enter the number of columns: ");
	scanf("%d", &c);

	int size = r * c * sizeof(int);

	int *M1 = (int*)malloc(size);
	int *M2 = (int*)malloc(size);
	int *res = (int*)malloc(size);

	printf("Enter the elements of matrix 1: ");
	for(int i=0; i<(r*c); i++)
		scanf("%d", &M1[i]);

	printf("Enter the elements of matrix 2: ");
	for(int i=0; i<(r*c); i++)
		scanf("%d", &M2[i]);

	printf("Entered Matrix 1:\n");
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
			printf("%d ", M1[i*c+j]);
		printf("\n");
	}

	printf("\nEntered Matrix 2:\n");
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
			printf("%d ", M2[i*c+j]);
		printf("\n");
	}

	int *d_M1, *d_M2, *d_res;

	cudaMalloc(&d_M1, size);
	cudaMalloc(&d_M2, size);
	cudaMalloc(&d_res, size);

	cudaMemcpy(d_M1, M1, size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_M2, M2, size, cudaMemcpyHostToDevice);

	ele_add<<<1, r*c>>>(d_M1, d_M2, d_res);

	cudaMemcpy(res, d_res, size, cudaMemcpyDeviceToHost);

	printf("\nResultant Matrix:\n");
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
			printf("%d ", res[i*c+j]);
		printf("\n");
	}

	cudaFree(d_M1);
	cudaFree(d_M2);
	cudaFree(d_res);

	return 0;
}