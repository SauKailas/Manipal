#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *Insert_Node(struct node *start, int data){
	struct node *new_node;
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=data;
	new_node->next=NULL;

	if(start==NULL)
		return new_node;

	struct node *ptr=start;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=new_node;
	return start;
}

void Display(struct node *start){
	if(start==NULL)
	{
		printf("List is EMPTY!\n");
		return;
	}

	struct node *ptr=start;
	while(ptr->next!=NULL)
	{
		printf("%d->", ptr->data);
		ptr=ptr->next;
	}
	printf("%d\n", ptr->data);
}

int main()
{
	int vert, edg;

	printf("Enter the number of vertices:\t");
	scanf("%d", &vert);
	printf("Enter the number of edges:\t");
	scanf("%d", &edg);

	int mat[vert][vert], adj;
	for(int i=0; i<vert; i++)
		for(int j=0; j<vert; j++)
			mat[i][j]=0;

	printf("\nSuppose the vertices are numbered from 1 to %d.\n", vert);
	for(int i=0; i<edg; i++)
	{
		printf("Enter the edge %d:\t", i+1);
		scanf("%d", &adj);
		int first=adj/10;
		int second=adj%10;
		mat[first-1][second-1]=1;
		mat[second-1][first-1]=1;
	}
	
	for(int i=0; i<vert; i++)
		for(int j=0; j<vert; j++)
			if(mat[i][j]!=1)
				mat[i][j]=0;
	
	printf("\nAdjacency Matrix:\n");
	for(int i=0; i<vert; i++)
	{
		for(int j=0; j<vert; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}

	printf("\nAdjacency Lists:\n");
	for(int i=0; i<vert; i++)
	{
		struct node *start=NULL;
		start=Insert_Node(start, i+1);

		for(int j=0; j<vert; j++)
		{
			if(mat[i][j]==1)
				start=Insert_Node(start, j+1);
		}
		printf("List of vertex %d: ", i+1);
		Display(start);
	}
		
	return 0;
}