/*Implement Matrix Multiplication

ALGORITHM:
for i<-0 to n-1 do
	for j<-0 to n-1 do
		C[i, j]<-0
		for k<-0 to n-1 do
			C[i, j]<-C[i, j]+A[i, k]*B[k, j]
return C
*/

#include<stdio.h>
#include<stdlib.h>

void Matrix_Multiplication(int mat1[][10], int mat2[][10], int nr, int nc, int mr, int mc, int res[][10]){
	for(int i=0; i<nr; i++)
		for(int j=0; j<mc; j++)
		{
			res[i][j]=0;
			for(int k=0; k<nc; k++)
				res[i][j]+=mat1[i][k]*mat2[k][j];
		}
}

int main()
{
	int nr, nc, mr, mc;

	printf("Enter dimensions of first matrix:\n");
	scanf("%d %d", &nr, &nc);

	printf("Enter dimensions of second matrix:\n");
	scanf("%d %d", &mr, &mc);

	if(nc!=mr)
	{
		printf("Invalid Dimensions!\n");
		exit(0);
	}

	int mat1[nr][nc], mat2[mr][mc], res[10][10];
	printf("Enter elements of first matrix:\n");
	for(int i=0; i<nr; i++)
		for(int j=0; j<nc; j++)
			scanf("%d", &mat1[i][j]);

	printf("Enter elements of second matrix:\n");
	for(int i=0; i<mr; i++)
		for(int j=0; j<mc; j++)
			scanf("%d", &mat2[i][j]);

	Matrix_Multiplication(mat1, mat2, nr, nc, mr, mc, res);
	printf("The resultant matrix is:\n");
	for(int i=0; i<nr; i++)
	{
		for(int j=0; j<nr; j++)
			printf("%d ", res[i][j]);
		printf("\n");
	}

	return 0;
}