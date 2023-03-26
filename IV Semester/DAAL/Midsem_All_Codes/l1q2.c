/*
Write a program to implement the following graph representations and display
them.
i. Adjacency list
ii. Adjacency matrix
*/

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

	if(!start)
		return new_node;

	struct node *ptr=start;
	while(ptr->next)
		ptr=ptr->next;
	ptr->next=new_node;
	return start;
}

void Display(struct node *start){
	if(!start)
	{
		printf("List is EMPTY!\n");
		return;
	}

	struct node *ptr=start;
	while(ptr->next)
	{
		printf("%d->", ptr->data);
		ptr=ptr->next;
	}
	printf("%d\n", ptr->data);
}

int main()
{
	int no_vert, no_edg;

	printf("Enter the number of vertices: ");
	scanf("%d", &no_vert);

	int mat[no_vert][no_vert];
	for(int i=0; i<no_vert; i++)
		for(int j=0; j<no_vert; j++)
			mat[i][j]=0;

	printf("Enter the number of edges: ");
	scanf("%d", &no_edg);

	for(int i=0; i<no_edg; i++)
	{
		int edg, v1, v2;
		printf("Enter the adjacent edge %d\n", i+1);
		scanf("%d", &edg);

		v1=(edg/10)%10;
		v2=edg%10;
		mat[v1-1][v2-1]=mat[v2-1][v1-1]=1;
	}

	printf("\nAdjacency Matrix:\n");
	for(int i=0; i<no_vert; i++)
	{
		for(int j=0; j<no_vert; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}

	for(int i=0; i<no_vert; i++)
	{
		struct node *start=NULL;
		start=Insert_Node(start, i+1);
		for(int j=0; j<no_vert; j++)
			if(mat[i][j]==1)
				start=Insert_Node(start, j+1);

		printf("\nAdjacency List for %d:\n", i+1);
		Display(start);
	}

	return 0;
}