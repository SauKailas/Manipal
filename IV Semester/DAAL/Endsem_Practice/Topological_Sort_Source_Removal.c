#include<stdio.h>

int vert;
int mat[10][10];
int queue[20];

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &vert);

    printf("Enter the adjacency matrix:\n");
    for(int i=0; i<vert; i++)
        for(int j=0; j<vert; j++)
            scanf("%d", &mat[i][j]);
}