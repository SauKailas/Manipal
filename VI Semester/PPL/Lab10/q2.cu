#include<stdio.h>
#include<stdlib.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

__global__ void Replace(int *A, int *B, int N)
{
	int tid = blockIdx.x* blockDim.x + threadIdx.x;

	for(int i=0; i<N; i++)
	{
		int ele = A[tid * N + i];
		int temp = ele;
		for(int j=0; j<tid; j++)
			ele *= temp;
		B[tid * N + i] = ele;
	}
}

int main()
{
	int M, N;

	printf("Enter the value of M: ");
	scanf("%d", &M);

	printf("Enter the value of N: ");
	scanf("%d", &N);

	int size = M * N * sizeof(int);

	int *A = (int*)malloc(size);
	int *B = (int*)malloc(size);

	printf("Enter the matrix elements:\n");
	for(int i=0; i<(M * N); i++)
		scanf("%d", &A[i]);

	printf("Entered Matrix:\n");
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
			printf("%d ", A[i * N + j]);
		printf("\n");
	}

	int *d_A, *d_B;

	cudaMalloc((void**)&d_A, size);
	cudaMalloc((void**)&d_B, size);

	cudaMemcpy(d_A, A, size, cudaMemcpyHostToDevice);

	Replace<<<1, M>>>(d_A, d_B, N);

	cudaMemcpy(B, d_B, size, cudaMemcpyDeviceToHost);

	printf("Resultant Matrix:\n");
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
			printf("%d ", B[i * N + j]);
		printf("\n");
	}

	cudaFree(d_A);
	cudaFree(d_B);

	return 0;
}