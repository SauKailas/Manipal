/*
Write a program to construct a binary tree to support the following operations. Assume no duplicate elements while constructing the tree.
i. Given a key, perform a search in the binary search tree. If the key is found then display “key found” else insert the key in the binary search tree.
ii. Display the tree using inorder, preorder and post order traversal methods
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *lchild;
	struct node *rchild;
};

struct node *Insert_Node(struct node *root, int data){

	if(!root)
	{
		struct node *new_node;
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=data;
		new_node->lchild=new_node->rchild=NULL;
		return new_node;
	}

	if(data<root->data)
		root->lchild=Insert_Node(root->lchild, data);
	else if(data>root->data)
		root->rchild=Insert_Node(root->rchild, data);
	else
		printf("Duplicates are NOT allowed!\n");
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

int Search(struct node *root, int data){
	if(!root)
		return 0;
	else if(data==root->data)
		return 1;
	else if(data<root->data)
		return Search(root->lchild, data);
	return Search(root->rchild, data);
}

int main()
{
	struct node *root=NULL;
	int ch, data, key;

	do{
		printf("\nSelect an Option:\n");
		printf("1. Insert Node\n");
		printf("2. Inorder Traversal\n");
		printf("3. Preorder Traversal\n");
		printf("4. Postorder Traversal\n");
		printf("5. Search Element\n");
		printf("6. Exit\n");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
				printf("Enter data to insert: ");
				scanf("%d", &data);
				root=Insert_Node(root, data);
				break;

			case 2:
				if(!root)
					printf("Tree is EMPTY!\n");
				else
					Inorder(root);
				break;

			case 3:
				if(!root)
					printf("Tree is EMPTY!\n");
				else
					Preorder(root);
				break;

			case 4:
				if(!root)
					printf("Tree is EMPTY!\n");
				else
					Postorder(root);
				break;

			case 5:
				if(!root)
					printf("Tree is EMPTY!\n");
				else
				{
					printf("Enter key to search: ");
					scanf("%d", &key);

					int flag=Search(root, key);
					if(flag)
						printf("Key is FOUND!\n");
					else
						printf("Key is NOT FOUND!\n");
					break;
				}
		}
	}while(ch!=6);

	return 0;
}
