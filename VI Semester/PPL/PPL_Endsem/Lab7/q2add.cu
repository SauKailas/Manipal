#include<stdio.h>
#include<stdlib.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

__global__ void row_selection_sort(int *M, int *res, int size)
{
	int rowid = threadIdx.x;
	int colid = threadIdx.y;
	int data = M[rowid * size + colid];
	int pos = 0;

	for(int i=0; i<size; i++)
		if(M[rowid * size + i] < data || (M[rowid * size + i] == data && i < pos))
			pos++;
	res[rowid * size + pos] = data;
}

int main()
{
	int r, c;

	printf("Enter the number of rows and columns: ");
	scanf("%d %d", &r, &c);
	int size = r * c * sizeof(int);

	int *M = (int*)malloc(size);
	int *res = (int*)malloc(size);

	printf("Enter the matrix elements: ");
	for(int i=0; i<(r*c); i++)
		scanf("%d", &M[i]);

	int *d_M, *d_res;

	cudaMalloc((void**)&d_M, size);
	cudaMalloc((void**)&d_res, size);

	cudaMemcpy(d_M, M, size, cudaMemcpyHostToDevice);

	row_selection_sort<<<1, (r, c, 1)>>>(d_M, d_res, c);

	cudaMemcpy(res, d_res, size, cudaMemcpyDeviceToHost);

	printf("RESULTS:\n");
	printf("Resultant Matrix:\n");
	for(int i=0; i<(r*c); i++)
	{
		if(i % c == 0)
			printf("\n");
		printf("%d ", res[i]);
	}

	cudaFree(d_M);
	cudaFree(d_res);
	free(M);
	free(res);

	return 0;
}