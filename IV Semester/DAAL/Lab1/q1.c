#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *lchild;
	struct node *rchild;
};

struct node *Insert_Node(struct node *root, int data){

	if(root==NULL)
	{
		struct node *new_node;
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=data;
		new_node->lchild=new_node->rchild=NULL;
		return new_node;
	}

	if(data<root->data)
		root->lchild=Insert_Node(root->lchild, data);
	else
		root->rchild=Insert_Node(root->rchild, data);
	return root;
}

int Search_Key(struct node *root, int key){
	if(root==NULL)
		return 0;
	else if(key==root->data)
		return 1;
	else if(key<root->data)
		return Search_Key(root->lchild, key);
	else
		return Search_Key(root->rchild, key);
}

struct node *Create_Tree(){
	struct node *root=NULL;
	int key;

	while(1);
	{
		printf("Enter key to insert [-1 to stop]: \t");
		scanf("%d", &key);

		if(key==-1)
			break;
		else if(Search_Key(root, key))
			printf("Key Found!\n");
		else
			root=Insert_Node(root, key);
	}
	return root;
}

void Inorder(struct node *root){
	if(root)
	{
		Inorder(root->lchild);
		printf("%d ", root->data);
		Inorder(root->rchild);
	}
}

void Preorder(struct node *root){
	if(root)
	{
		printf("%d ", root->data);
		Preorder(root->lchild);
		Preorder(root->rchild);
	}
}

void Postorder(struct node *root){
	if(root)
	{
		Postorder(root->lchild);
		Postorder(root->rchild);
		printf("%d ", root->data);
	}
}

int main()
{
	struct node *root=Create_Tree();

	printf("Inorder Traversal: \t");
	Inorder(root);
	printf("\n");
	printf("Preorder Traversal: \t");
	Preorder(root);
	printf("\n");
	printf("Postorder Traversal: \t");
	Postorder(root);
	printf("\n");
	return 0;
}
