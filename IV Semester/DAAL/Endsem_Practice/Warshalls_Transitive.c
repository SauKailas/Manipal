#include<stdio.h>

int vert;
int edg;
int mat[10][10];

int Max(int a, int b){
    return a>b?a:b;
}

void Warshalls(){
    for(int k=1; k<=vert; k++)
        for(int i=1; i<=vert; i++)
            for(int j=1; j<=vert; j++)
                mat[i][j]=Max(mat[i][j], mat[i][k] && mat[k][j]);
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &vert);

    printf("Enter the number of edges: ");
    scanf("%d", &edg);

    for(int i=1; i<=vert; i++)
        for(int j=1; j<=vert; j++)
            mat[i][j]=0;

    int m, n;
    for(int i=1; i<=edg; i++)
    {
        printf("Enter the end vertices of egde %d: ", i);
        scanf("%d %d", &m, &n);
        mat[m][n]=1;
    }

    printf("\nAdjacency Matrix:\n");
    for(int i=1; i<=vert; i++)
    {
        for(int j=1; j<=vert; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }

    Warshalls();

    printf("\nTransitive Closure:\n");
    for(int i=1; i<=vert; i++)
    {
        for(int j=1; j<=vert; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }

    return 0;
}