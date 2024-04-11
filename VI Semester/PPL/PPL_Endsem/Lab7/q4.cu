#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

__global__ void sin_rad(float *A, float *B)
{
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	float val = A[tid];
	float res = sin(val);
	B[tid] = res;x
}

int main()
{
	int N;

	printf("Enter the value of N: ");
	scanf("%d", &N);
	int size = N * sizeof(float);

	float *A = (float*)malloc(size);
	float *B = (float*)malloc(size);

	printf("Enter the elements of A: ");
	for(int i=0; i<N; i++)
		scanf("%f", &A[i]);

	float *d_A, *d_B;

	cudaMalloc((void**)&d_A, size);
	cudaMalloc((void**)&d_B, size);

	cudaMemcpy(d_A, A, size, cudaMemcpyHostToDevice);

	sin_rad<<<1, N>>>(d_A, d_B);

	cudaMemcpy(B, d_B, size, cudaMemcpyDeviceToHost);

	printf("RESULTS:\n");
	printf("B : ");
	for(int i=0; i<width; i++)
		printf("%.3f ", B[i]);
	printf("\n");

	cudaFree(d_A);
	cudaFree(d_B);
	free(A);
	free(B);

	return 0;
}