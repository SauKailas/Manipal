#include<stdio.h>

int vert;
int mat[10][10];
int start;
int cost[10][10];
int distance[20];
int pred[20];
int vis[20];
int count=1;
int mindistance;
int nextnode;

void Dijkstras(){

    for(int i=0; i<vert; i++)
        for(int j=0; j<vert; j++)
        {
            if(mat[i][j]==0)
                cost[i][j]=9999;
            else    
                cost[i][j]=mat[i][j];
        }

    for(int i=0; i<vert; i++)
    {
        distance[i]=cost[start][i];
        pred[i]=start;
        vis[i]=0;
    }

    distance[start]=0;
    vis[start]=1;

    while(count<vert-1)
    {
        mindistance=9999;

        for(int i=0; i<vert; i++)
            if(distance[i]<mindistance && !vis[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }

        vis[nextnode]=1;
        for(int i=0; i<vert; i++)
            if(!vis[i])
                if(mindistance+cost[nextnode][i]<distance[i])
                {
                    distance[i]=mindistance+cost[nextnode][i];
                    pred[i]=nextnode;
                }

        count++;
    }

    for(int i=0; i<vert; i++)
        if(i!=start)
            printf("Distance from %d to %d is %d\n", start, i, distance[i]);
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &vert);

    printf("Enter the cost adjacency matrix:\n");
    for(int i=0; i<vert; i++)
        for(int j=0; j<vert; j++)
            scanf("%d", &mat[i][j]);

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    Dijkstras();

    return 0;
}