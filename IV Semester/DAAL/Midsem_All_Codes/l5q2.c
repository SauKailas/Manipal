/*
Write a program to find diameter of a binary tree. 
Diameter of a binary tree is the longest path between any two nodes.
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *lchild;
	struct node *rchild;
};

struct node *Create_Binary_Tree(int data){
	int x;

	while(data!=-1){
		struct node *new_node;
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=data;
		new_node->lchild=new_node->rchild=NULL;

		printf("Enter left child of %d: ", data);
		scanf("%d", &x);
		new_node->lchild=Create_Binary_Tree(x);

		printf("Enter right child of %d: ", data);
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

int Max(int a, int b){
	return a>b?a:b;
}

int Height(struct node *root){
	if(!root)
		return 0;
	return 1+Max(Height(root->lchild), Height(root->rchild));
}

int Diameter(struct node *root){
	if(!root)
		return 0;

	int lheight=Height(root->lchild);
	int rheight=Height(root->rchild);
	int ldiameter=Diameter(root->lchild);
	int rdiameter=Diameter(root->rchild);

	return Max(1+lheight+rheight, Max(ldiameter, rdiameter));
}

int main()
{
	int data;
	struct node *root=NULL;

	printf("Enter root data [-1 for NULL]: ");
	scanf("%d", &data);
	root=Create_Binary_Tree(data);

	printf("Inorder Traversal: ");
	Inorder(root);

	printf("\nDiameter of Tree: %d\n", Diameter(root));

	return 0;
}