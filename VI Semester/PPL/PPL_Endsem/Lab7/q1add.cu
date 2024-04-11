#include<stdio.h>
#include<stdlib.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

__global__ void linear_function(int *X, int *Y, int *Z, int alfa)
{
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int res = X[tid] * alfa + Y[tid];
	Z[tid] = res;
}

int main()
{
	int N, alfa;

	printf("Enter the number of elements: ");
	scanf("%d", &N);
	int size = N * sizeof(int);

	int *X = (int*)malloc(size);
	int *Y = (int*)malloc(size);
	int *Z = (int*)malloc(size);

	printf("Enter the value of alfa: ");
	scanf("%d", &alfa);

	printf("Enter the elements of X: ");
	for(int i=0; i<N; i++)
		scanf("%d", &X[i]);

	printf("Enter the elements of Y: ");
	for(int i=0; i<N; i++)
		scanf("%d", &Y[i]);

	int *d_X, *d_Y, *d_Z;

	cudaMalloc((void**)&d_X, size);
	cudaMalloc((void**)&d_Y, size);
	cudaMalloc((void**)&d_Z, size);

	cudaMemcpy(d_X, X, size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_Y, Y, size, cudaMemcpyHostToDevice);

	linear_function<<<1, N>>>(d_X, d_Y, d_Z, alfa);

	cudaMemcpy(Z, d_Z, size, cudaMemcpyDeviceToHost);

	printf("RESULTS:\n");
	printf("Z : ");
	for(int i=0; i<N; i++)
		printf("%d ", Z[i]);
	printf("\n");

	cudaFree(d_X);
	cudaFree(d_Y);
	cudaFree(d_Z);
	free(X);
	free(Y);
	free(Z);

	return 0;
}