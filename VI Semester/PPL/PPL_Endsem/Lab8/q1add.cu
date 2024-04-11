#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

__global__ void Reverse_Words(char *str, int word_len)
{
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	char temp;

	for(int i=0; i<(word_len/2); i++)
	{
		temp = str[tid + i];
		str[tid + i] = str[tid + word_len - i - 1];
		str[tid + word_len - i + 1] = temp;
	}
}

int main()
{
	int N, word_len;
	char S[100], str[100];
	int len = 0;

	printf("Enter the value of N: ");
	scanf("%d", &N);

	printf("Enter the length of each word: ");
	scanf("%d", &word_len);

	printf("Enter the string: ");
	gets(S);

	for(int i=0; i<strlen(S); i++)
	{
		if(S[i] == ' ')
			continue;
		str[len++] = S[i];
	}
	len--;

	char *d_str

	cudaMalloc((void**)&d_str, len * sizeof(char));

	cudaMemcpy(d_str, str, len * sizeof(char), cudaMemcpyHostToDevice);

	Reverse_Words<<<1, N>>>(d_str, word_len);

	cudaMemcpy(str, d_str, len * sizeof(char), cudaMemcpyDeviceToHost);

	printf("RESULTS:\n");
	printf("Reversed Words: ");
	for(int i=0; i<len; i++)
	{
		if(i % word_len == 0)
			printf(" ");
		printf("%c", str[i]);
	}

	cudaFree(d_str);

	return 0;
}