#include<stdio.h>
#include<stdlib.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

__global__ void convolution_1d(int *N, int *P, int *M, int width, int mask_width)
{
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	int N_start_point = i - (mask_width / 2);
	int Pval = 0,

	for(int j=0; j<mask_width; j++)
		if(N_start_point + j >= 0 && N_start_point + j < width)
			Pval += N[N_start_point + j] * M[j];
	P[i] = Pval;
}

int main()
{
	int width, mask_width;

	printf("Enter the input array width: ");
	scanf("%d", &width);

	printf("Enter the mask width: ");
	scanf("%d", &mask_width);

	int *N = (int*)malloc(width * sizeof(int));
	int *P = (int*)malloc(width * sizeof(int));
	int *M = (int*)malloc(mask_width * sizeof(int));

	printf("Enter the input array elements: ");
	for(int i=0; i<width; i++)
		scanf("%d", &N[i]);

	printf("Enter the mask elements: ");
	for(int i=0; i<mask_width; i++)
		scanf("%d", &M[i]);

	int *d_N, *d_P, *d_P;

	cudaMalloc((void**)&d_N, width * sizeof(int));
	cudaMalloc((void**)&d_P, width * sizeof(int));
	cudaMalloc((void**)&d_M, mask_width * sizeof(int));

	cudaMemcpy(d_N, N, width * sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(d_M, M, mask_width * sizeof(int), cudaMemcpyHostToDevice);

	convolution_1D<<<1, width>>>(d_N, d_P, d_M, width, mask_width);

	cudaMemcpy(P, d_P, width * sizeof(int), cudaMemcpyDeviceToHost);

	printf("RESULTS:\n");
	printf("P : ");
	for(int i=0; i<width; i++)
		printf("%d ", P[i]);
	printf("\n");

	cudaFree(d_N);
	cudaFree(d_P);
	cudaFree(d_M);
	free(N);
	free(P);
	free(M);

	return 0;
}