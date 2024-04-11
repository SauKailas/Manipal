#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

__global__ void Count_Word_Occurrences(char *str, char *word, int str_len, int word_len, int count)
{
	int tid = threadIdx.x;

	while(tid < str_len)
	{
		int i = 0;
		while(i < word_len && str[tid + i] == word[i])
			i++;

		if(i == word_len)
		{
			atomicAdd(count, 1);
			tid += word_len;
		}
		else
			tid++;
	}
}

int main()
{
	int str_len, word_len;

	printf("Enter string length: ");
	scanf("%d", &str_len);

	printf("Enter word length: ");
	scanf("%d", &word_len);

	char *str = (char*)malloc(str_len * sizeof(char));
	char *word = (char*)malloc(word_len * sizeof(char));

	printf("Enter the string: ");
	gets(str);

	printf("Enter the word: ");
	gets(word);

	char *d_word, *d_str;
	int *count, *d_count;

	cudaMalloc((void**)&d_str, str_len * sizeof(char));
	cudaMalloc((void**)&d_word, word_len * sizeof(char));
	cudaMalloc((void**)&d_count, sizeof(int));

	cudaMemcpy(d_str, str, str_len * sizeof(char), cudaMemcpyHostToDevice);
	cudaMemcpy(d_word, word, word_len * sizeof(char), cudaMemcpyHostToDevice);
	cudaMemset(d_count, 0, sizeof(int));

	Count_Word_Occurrences<<<1, 1>>>(d_str, d_word, str_len, word_len, d_count);

	cudaMemcpy(count, d_count, sizeof(int), cudaMemcpyDeviceToHost);

	printf("RESULTS:\n");
	printf("Number of Occurrences: %d\n", count);

	cudaFree(d_str);
	cudaFree(d_word);
	cudaFree(d_count);
	free(str);
	free(word);
	free(count);

	return 0;
}