#include<stdio.h>
#include<stdlib.h>

int push_order[10];
int push_idx=0;
int pop_order[10];
int pop_idx=0;

struct GRAPH{
    int vert;
    int edg;
    int adj[10][10];
    int vis[10];
};

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

void DFS(struct GRAPH *G, int u){
    G->vis[u]=1;
    push_order[push_idx++]=u;
    for(int i=0; i<G->vert; i++)
        if(!G->vis[i] && G->adj[u][i])
            DFS(G, i);
    pop_order[pop_idx++]=u;
}

void DFS_Traversal(struct GRAPH *G){
    for(int i=0; i<G->vert; i++)
        if(!G->vis[i])
            DFS(G, i);
}

int main()
{
    struct GRAPH *G=getGraph();

    DFS_Traversal(G);

    printf("\nPush Order: ");
    for(int i=0; i<G->vert; i++)
        printf("%d ", push_order[i]);
    printf("\nPop Order: ");
    for(int i=0; i<G->vert; i++)
        printf("%d ", pop_order[i]);
    printf("\nTopological Order: ");
    for(int i=G->vert-1; i>=0; i--)
        printf("%d ", push_order[i]);
    printf("\n");
    
    return 0;
}