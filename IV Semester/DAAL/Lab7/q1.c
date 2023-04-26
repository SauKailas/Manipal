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

int Max(int a, int b){
    return a>b?a:b;
}

int Height(struct node *root){
    return 1+Max(Height(root->lchild), Height(root->rchild));
}

int Balance_Factor(struct node *root){
	if(root==NULL)
		return 0;
	int l=Balance_Factor(root->lchild);
	int r=Balance_Factor(root->rchild);
	int f=l-r;
	printf("Balance Factor of node %d is %d\n", root->data, f);
	return 1+Max(l, r);
}

int main()
{
    struct node *root=NULL;
    int ch, data;

    do{
        printf("\nSelect an Option:\n");
        printf("1. Insert Node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Balance Factor\n");
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
                    printf("Root Data ----- Balance Factor\n");
                    Balance_Factor(root);
                }
                break;
        }
    }while(ch!=6);

    return 0;
}