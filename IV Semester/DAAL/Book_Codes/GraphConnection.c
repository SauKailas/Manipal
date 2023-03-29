#include<stdio.h>
#include<stdlib.h>

struct GRAPH{
	int vert;
	int edg;
	int adj[10][10];
	int vis[10];
};

struct GRAPH *getGraph(){
	struct GRAPH* G;
	G=(struct GRAPH*)malloc(sizeof(struct GRAPH));

	printf("Enter the number of vertices and edges:\n");
	scanf("%d %d", &G->vert, &G->edg);

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
	for(int i=0; i<G->vert; i++)
		if(!G->vis[i] && G->adj[u][i])
		{
			printf("\n%d->%d", u, i);
			DFS(G, i);
		}
}

int main()
{
	struct GRAPH *G=getGraph();

	DFS(G, 0);

	int count=0;
	for(int i=0; i<G->vert; i++)
		if(G->vis[i])
			count++;

	if(count==G->vert)
		printf("\nGraph IS connected!\n");
	else
		printf("\nGraph is NOT connected!\n");

	return 0;
}