#include<stdio.h>
#include<stdlib.h>

int queue[10];
int front=0;
int rear=0;

struct GRAPH{
    int vert;
    int edg;
    int adj[10][10];
    int vis[10];
};

void Enqueue(int n){
    queue[rear++]=n;
}

int Dequeue(){
    return queue[front++];
}

struct GRAPH *getGraph(){
    struct GRAPH *G;
    G=(struct GRAPH*)malloc(sizeof(struct GRAPH));

    printf("Enter the number of vertices: ");
    scanf("%d", &G->vert);

    printf("Enter the number of edges: ");
    scanf("%d", &G->edg);

    printf("Enter the adjacency matrix:\n");
    for(int i=0; i<G->vert; i++)
        for(int j=0; j<G->vert; j++)
            scanf("%d", &G->adj[i][j]);

    for(int i=0; i<G->vert; i++)
        G->vis[i]=0;

    return G;
}

void BFS_Traversal(struct GRAPH *G){
    int u=Dequeue();

    while(front<=rear)
    {
        printf("%d ", u);
        for(int i=0; i<G->vert; i++)
            if(!G->vis[i] && G->adj[u][i])
            {
                G->vis[i]=1;
                Enqueue(i);
            }
            u=Dequeue();
    }
}

int main()
{
    struct GRAPH *G=getGraph();

    printf("\nPush Order: ");
    for(int i=0; i<G->vert; i++)
        if(!G->vis[i])
        {
            G->vis[i]=1;
            Enqueue(i);
            BFS_Traversal(G);
        }
    printf("\n");
    
    return 0;
}