#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

__global__ void Generate_T(char *Sin, char *T, int *idx)
{
	int tid = blockIdx.x * blockDim.x + threadIdx.x;

	for(int i=0; i<=tid; i++)
		T[idx[tid + i]] = Sin[tid];
}

int main()
{
	char Sin[100], T[100];
	int len;
	int idx[100];

	printf("Enter a word: ");
	scanf("%s", Sin);
	len = strlen(Sin);

	idx[0] = 0;
	for(int i=1; i<len; i++)
		idx[i] = idx[i-1] + i;

	char *d_Sin, *d_T;
	int *d_idx;

	cudaMalloc((void**)&d_Sin, len * sizeof(char));
	cudaMalloc((void**)&d_T, (len * len) * sizeof(char));
	cudaMalloc((void**)&d_idx, (len * sizeof(int)));

	cudaMemcpy(d_Sin, Sin, len * sizeof(char), cudaMemcpyHostToDevice);
	cudaMemcpy(d_idx, idx, len * sizeof(int), cudaMemcpyHostToDevice);

	Generate_T<<<1, len>>>(d_Sin, d_T, d_idx);

	cudaMemcpy(T, d_T, (len * len) * sizeof(char), cudaMemcpyDeviceToHost);

	printf("RESULTS:\n");
	printf("T : %s\n", T);

	cudaFree(d_Sin);
	cudaFree(d_T);
	cudaFree(d_idx);

	return 0;
}