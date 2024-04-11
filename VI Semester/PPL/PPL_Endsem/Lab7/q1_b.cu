#include<stdio.h>
#include<stdlib.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

__global__ void vec_add(int *A, int *B, int *C)
{
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	C[tid] = A[tid] + B[tid];
}

int main()
{
	int N;

	printf("Enter the value of N: ");
	scanf("%d", &N);
	int size = N * sizeof(int);

	int *A = (int*)malloc(N * sizeof(size));
	int *B = (int*)malloc(N * sizeof(size));
	int *C = (int*)malloc(N * sizeof(size));

	printf("Enter the elements of A: ");
	for(int i=0; i<N; i++)
		scanf("%d", &A[i]);

	printf("Enter the elements of B: ");
	for(int i=0; i<N; i++)
		scanf("%d", &B[i]);

	int *d_A, *d_B, *d_C;

	cudaMalloc((void**)&d_A, size);
	cudaMalloc((void**)&d_B, size);
	cudaMalloc((void**)&d_C, size);

	cudaMemcpy(d_A, A, size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_B, B, size, cudaMemcpyHostToDevice);

	vec_add<<<1, N>>>(d_A, d_B, d_C);

	cudaMemcpy(C, d_C, size, cudaMemcpyDeviceToHost);

	printf("RESULTS:\n");
	printf("C : ");
	for(int i=0; i<N; i++)
		printf("%d ", C[i]);
	printf("\n");

	cudaFree(d_A);
	cudaFree(d_B);
	cudaFree(d_C);
	free(A);
	free(B);
	free(C);

	return 0;
}