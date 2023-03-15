#include<stdio.h>
#include<stdlib.h>

int opcount=0;

struct node{
	int data;
	struct node *lchild;
	struct node *rchild;
};

int Count_Nodes(struct node *root){
	if(!root)
		return 0;

	opcount++;
	int l=Count_Nodes(root->lchild);
	int r=Count_Nodes(root->rchild);
	return 1+l+r;
}

struct node *Create_Binary_Tree(int data){
	int x;

	while(data!=-1)
	{
		struct node *new_node;
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=data;

		printf("Enter the left child of %d: ", data);
		scanf("%d", &x);
		new_node->lchild=Create_Binary_Tree(x);

		printf("Enter the right child of %d: ", data);
		scanf("%d", &x);
		new_node->rchild=Create_Binary_Tree(x);

		return new_node;
	}
	return NULL;
}

void Inorder(struct node *root){
	if(root)
	{
		Inorder(root->lchild);
		printf("%d ", root->data);
		Inorder(root->rchild);
	}
}

int main()
{
	struct node *root;
	int data;

	printf("Enter the root data [-1 for NULL]: ");
	scanf("%d", &data);
	root=Create_Binary_Tree(data);

	printf("\nInorder Traversal: ");
	Inorder(root);

	printf("\nNumber of Nodes: %d", Count_Nodes(root));
	printf("\nOperation Count: %d\n", opcount);

	return 0;
}