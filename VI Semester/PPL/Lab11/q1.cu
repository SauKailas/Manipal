#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

__global__ void matrixMultiply(int *a, int *b, int *c, int rows_a, int cols_a, int cols_b) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;

    if (row < rows_a && col < cols_b) {
        int sum = 0;
        for (int k = 0; k < cols_a; ++k) {
            sum += a[row * cols_a + k] * b[k * cols_b + col];
        }
        c[row * cols_b + col] = sum;
    }
}

int main() {
    int rows_a, cols_a, rows_b, cols_b;

    printf("Enter the number of rows and columns for matrix A: ");
    scanf("%d %d", &rows_a, &cols_a);

    printf("Enter the number of rows and columns for matrix B: ");
    scanf("%d %d", &rows_b, &cols_b);

    if (cols_a != rows_b) {
        printf("Matrix multiplication not possible. Number of columns in A must be equal to the number of rows in B.\n");
        return 1;
    }

    int *a, *b, *c; 
    int *d_a, *d_b, *d_c; 
    int size_a = rows_a * cols_a * sizeof(int);
    int size_b = rows_b * cols_b * sizeof(int);
    int size_c = rows_a * cols_b * sizeof(int);

    a = (int*)malloc(size_a);
    b = (int*)malloc(size_b);
    c = (int*)malloc(size_c);

    printf("Enter the elements for matrix A (%d x %d):\n", rows_a, cols_a);
    for (int i = 0; i < rows_a; ++i) {
        for (int j = 0; j < cols_a; ++j) {
            scanf("%d", &a[i * cols_a + j]);
        }
    }

    printf("Enter the elements for matrix B (%d x %d):\n", rows_b, cols_b);
    for (int i = 0; i < rows_b; ++i) {
        for (int j = 0; j < cols_b; ++j) {
            scanf("%d", &b[i * cols_b + j]);
        }
    }

    cudaMalloc((void**)&d_a, size_a);
    cudaMalloc((void**)&d_b, size_b);
    cudaMalloc((void**)&d_c, size_c);

    cudaMemcpy(d_a, a, size_a, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, size_b, cudaMemcpyHostToDevice);

    dim3 dimBlock(16, 16); 
    dim3 dimGrid(ceil((float)cols_b / dimBlock.x), ceil((float)rows_a / dimBlock.y));


    matrixMultiply<<<dimGrid, dimBlock>>>(d_a, d_b, d_c, rows_a, cols_a, cols_b);

    cudaMemcpy(c, d_c, size_c, cudaMemcpyDeviceToHost);

    printf("Result Matrix:\n");
    for (int i = 0; i < rows_a; ++i) {
        for (int j = 0; j < cols_b; ++j) {
            printf("%d ", c[i * cols_b + j]);
        }
        printf("\n");
    }

    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    free(a);
    free(b);
    free(c);

    return 0;
}
