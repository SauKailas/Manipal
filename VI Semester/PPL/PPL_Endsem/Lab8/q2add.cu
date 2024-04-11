#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

__global__ void Replicate_Word(char *Sin, char *Sout, int len, int N)
{
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	int pos = tid;

	for(int i=0; i<N; i++)
	{
		Sout[pos] = Sin[tid];
		pos += len,
	}
}

int main()
{
	char Sin[100], Sout;
	int len;
	int N;

	printf("Enter Sin: ");
	scanf("%s", Sin);
	len = strlen(Sin);

	printf("Enter the value of N: ");
	scanf("%d", &N);

	char *d_Sin, *d_Sout;

	cudaMalloc((void**)&d_Sin, len * sizeof(char));
	cudaMalloc((void**)&d_Sout, (len * N) * sizeof(char));

	cudaMemcpy(d_Sin, Sin, len * sizeof(char), cudaMemcpyHostToDevice);

	Replicate_Word<<<1, len>>>(d_Sin, d_Sout, len, N);

	cudaMalloc(Sout, d_Sout, (len * N) * sizeof(char), cudaMemcpyDeviceToHost);

	printf("RESULTS:\n");
	printf("Sout : %s\n", Sout);

	cudaFree(d_Sin);
	cudaFree(d_Sout);

	return 0;
}