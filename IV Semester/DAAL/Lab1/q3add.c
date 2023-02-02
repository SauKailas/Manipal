#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *lchild;
	struct node *rchild;
};

struct node *Insert_Node(struct node *start, int data){
	struct node *new_node, *ptr;
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=data;

	if(start==NULL)
	{
		new_node->lchild=new_node->rchild=NULL;
		return new_node;
	}

	ptr=start;
	while(ptr->rchild!=NULL)
		ptr=ptr->rchild;
	new_node->lchild=ptr;
	ptr->rchild=new_node;
	return start;
}

void Display(struct node *start){
	if(start==NULL)
	{
		printf("List is EMPTY!\n");
		return;
	}

	struct node *ptr=start->rchild;
	while(ptr->rchild)
	{
		printf("%d<->", ptr->data);
		ptr=ptr->rchild;
	}
	printf("%d\n", ptr->data);
}

struct node *Create_BT(int data){
	int x;

	if(data!=-1)
	{
		struct node *new_node;
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=data;

		printf("Enter the left child of %d: ", data);
		scanf("%d", &x);
		new_node->lchild=Create_BT(x);

		printf("Enter the right child of %d: ", data);
		scanf("%d", &x);
		new_node->rchild=Create_BT(x);

		return new_node;
	}
	return NULL;
}

void Convert_to_LL(struct node *root, struct node *start){
	if(root)
	{
		Convert_to_LL(root->lchild, start);
		start=Insert_Node(start, root->data);
		Convert_to_LL(root->rchild, start);
	}
}

int main()
{
	struct node *root, *start;
	start=(struct node*)malloc(sizeof(struct node));
	start->data=0;
	start->lchild=start->rchild=NULL;

	root=(struct node*)malloc(sizeof(struct node));
	int data;

	printf("Enter the data for root: ");
	scanf("%d", &data);
	root=Create_BT(data);

	Convert_to_LL(root, start);
	printf("\nLinked List Representation:\n");
	Display(start);
	printf("\n");

	return 0;
}