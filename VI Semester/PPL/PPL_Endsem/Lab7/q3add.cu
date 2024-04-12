#include<stdio.h>
#include<stdlib.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

__global__ void oddEven(int *A, int N)
{
	int tid = threadIdx.x;
	int idx = 2 * tid + 1;
	if(idx + 1 < N)
	{
		if(A[idx] > A[idx+1])
		{
			int temp = A[idx];
			A[idx] = A[idx+1];
			A[idx+1] = temp;
		}
	}
}

__global__ void evenOdd(int *A, int N)
{
	int tid = threadIdx.x;
	int idx = 2 * tid;
	if(idx + 1 < N)
	{
		if(A[idx] > A[idx+1])
		{
			int temp = A[idx];
			A[idx] = A[idx+1];
			A[idx+1] = temp;
		}
	}
}

int main()
{
	int N;
	int size;

	printf("Enter the number of elements: ");
	scanf("%d", &N);
	size = N * sizeof(int);

	int *A = (int*)malloc(size);

	printf("Enter the array elements: ");
	for(int i=0; i<N; i++)
		scanf("%d", &A[i]);

	int *d_A;

	cudaMalloc((void**)&d_A, size);
	cudaMemcpy(d_A, A, size, cudaMemcpyHostToDevice);

	dim3 dimGrid(1, 1, 1);
	dim3 dimBlock(ceil(N/2), 1, 1);

	for(int i=0; i<N/2; i++)
	{
		oddEven<<<dimGrid, dimBlock>>>(d_A, N);
		evenOdd<<<dimGrid, dimBlock>>>(d_A, N);
	}

	cudaMemcpy(A, d_A, size, cudaMemcpyDeviceToHost);

	printf("RESULTS:\n");
	printf("Sorted Array: ");
	for(int i=0; i<N; i++)
		printf("%d ", A[i]);
	printf("\n");

	cudaFree(d_A);
	free(A);

	return 0;
}