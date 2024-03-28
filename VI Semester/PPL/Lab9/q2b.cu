#include<stdio.h>
#include<stdlib.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

__global__ void matrix_mult_colwise(int *A, int *B, int *C, int ha, int hb)
{
	int colIdB = blockIdx.x * blockDim.x + threadIdx.x;
	int wb = blockDim.x;
	int sum;

	for(int rowIdA = 0; rowIdA < ha; rowIdA++)
	{
		sum = 0;
		for(int k = 0; k < hb; k++)
			sum += A[rowIdA * hb + k] * B[k * wb + colIdB];
		C[rowIdA * wb + colIdB] = sum;
	}
}

int main()
{
	int wa, wb, ha, hb;

	printf("Enter the dimensions of matrix A: ");
	scanf("%d %d", &ha, &wa);

	printf("Enter the dimensions of matrix B: ");
	scanf("%d %d", &hb, &wb);

	int sizeA = wa * ha * sizeof(int);
	int sizeB = wb * hb * sizeof(int);
	int sizeC = ha * wb * sizeof(int);

	int *A = (int*)malloc(sizeA);
	int *B = (int*)malloc(sizeB);
	int *C = (int*)malloc(sizeC);

	printf("Enter the elements of matrix A: ");
	for(int i=0; i<(wa*ha); i++)
		scanf("%d", &A[i]);

	printf("Enter the elements of matrix B: ");
	for(int i=0; i<(wb*hb); i++)
		scanf("%d", &B[i]);

	int *d_A, *d_B, *d_C;

	cudaMalloc((void**)&d_A, sizeA);
	cudaMalloc((void**)&d_B, sizeB);
	cudaMalloc((void**)&d_C, sizeB);

	cudaMemcpy(d_A, A, sizeA, cudaMemcpyHostToDevice);
	cudaMemcpy(d_B, B, sizeB, cudaMemcpyHostToDevice);

	dim3 dimGrid(1, 1, 1);
	dim3 dimBlock(wb, 1, 1);
	matrix_mult_colwise<<<dimGrid, dimBlock>>>(d_A, d_B, d_C, ha, hb);

	cudaMemcpy(C, d_C, sizeC, cudaMemcpyDeviceToHost);

	printf("Resultant Matrix:\n");
	for(int i=0; i<ha; i++)
	{
		for(int j=0; j<wb; j++)
			printf("%d ", C[i]);
		printf("\n");
	}

	cudaFree(d_A);
	cudaFree(d_B);
	cudaFree(d_C);

	return 0;
}