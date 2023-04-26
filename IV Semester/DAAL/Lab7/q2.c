#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
};

int Max(int a, int b){
    return a>b?a:b;
}

//Function to get height of a node
int Height(struct node *node){
    if(!node)
        return 0;
    return 1+Max(Height(node->lchild), Height(node->rchild));
}

//Function to get balance factor of a node
int Balance_Factor(struct node *node){
    return Height(node->lchild)-Height(node->rchild);
}

//Function to right-rotate subtree rooted at x
struct node *Right_Rotate(struct node *x){
    struct node *y=x->lchild;
    struct node *z=y->rchild;

    y->rchild=x;
    x->lchild=z;
    return y;       //Return new root
}

//Function to left-rotate subtree rooted at x
struct node *Left_Rotate(struct node *x){
    struct node *y=x->rchild;
    struct node *z=y->lchild;

    y->lchild=x;
    x->rchild=z;
    return y;
}

//Inorder traversal to display the AVL tree
void Inorder(struct node *root){
    if(root)
    {
        Inorder(root->lchild);
        printf("%d ", root->data);
        Inorder(root->rchild);
    }
}

//Function to insert a node in the AVL tree
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
    {
        printf("Duplicates are NOT allowed!\n");
        return root;
    }

    int balance=Balance_Factor(root);

    //Left-skewed case
    if(balance>1 && data<root->lchild->data)
        return Right_Rotate(root);

    //Right-skewed case
    if(balance<-1 && data>root->rchild->data)
        return Left_Rotate(root);

    //Left-right case
    if(balance>1 && data>root->lchild->data)
    {
        root->lchild=Left_Rotate(root->lchild);
        return Right_Rotate(root);
    }

    //Right-left case
    if(balance<-1 && data<root->rchild->data)
    {
        root->rchild=Right_Rotate(root->rchild);
        return Left_Rotate(root);
    }

    return root;
}

int main()
{
    int ch, data;
    struct node *root=NULL;

    do{
        printf("\nSelect an Option:\n");
        printf("1. Insert a Node\n");
        printf("2. Inorder Traversal of AVL Tree\n");
        printf("3. Exit\n");
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
                {
                    printf("\nInorder Traversal: ");
                    Inorder(root);
                    printf("\n");
                }
                break;
        }
    }while(ch!=3);

    return 0;
}