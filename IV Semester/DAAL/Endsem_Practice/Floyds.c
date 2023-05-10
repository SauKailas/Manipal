#include<stdio.h>

int vert;
int edg;
int mat[10][10];

int Min(int a, int b){
    return a>b?b:a;
}

void Floyds(){
    for(int k=1; k<=vert; k++)
        for(int i=1; i<=vert; i++)
            for(int j=1; j<=vert; j++)
            {
                if(i==j)
                    mat[i][j]=0;
                else
                    mat[i][j]=Min(mat[i][j], mat[i][k]+mat[k][j]);
            }
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &vert);

    printf("Enter the number of edges: ");
    scanf("%d", &edg);

    for(int i=1; i<=vert; i++)
        for(int j=1; j<=vert; j++)
            mat[i][j]=9999;

    int m, n, w;
    for(int i=1; i<=edg; i++)
    {
        printf("Enter the end vertices of edge %d and the weight: ", i);
        scanf("%d %d %d", &m, &n, &w);
        mat[m][n]=w;
    } 

    printf("\nCost adjacency matrix:\n");
    for(int i=1; i<=vert; i++)
    {
        for(int j=1; j<=vert; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }  

    Floyds();

    printf("\nTransitive Closure Matrix:\n");
    for(int i=1; i<=vert; i++)
    {
        for(int j=1; j<=vert; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }

    printf("\nShortest Paths:\n");
    for(int i=1; i<=vert; i++)
        for(int j=1; j<=vert; j++)
            if(i!=j)
                printf("<%d, %d> = %d\n", i, j, mat[i][j]);

    return 0;
}