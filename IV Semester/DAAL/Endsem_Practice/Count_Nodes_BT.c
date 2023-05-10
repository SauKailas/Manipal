#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
};

struct  node *Create_Binary_Tree(int data){
    int x;

    while(data!=-1)
    {
        struct node *new_node;
        new_node=(struct node*)malloc(sizeof(struct node));
        new_node->data=data;

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

int Count_Nodes(struct node *root){
    if(!root)
        return 0;

    int l=Count_Nodes(root->lchild);
    int r=Count_Nodes(root->rchild);
    return l+r+1;
}

int main()
{
    struct node *root;
    int data;

    printf("Enter root data: ");
    scanf("%d", &data);
    root=Create_Binary_Tree(data);

    printf("Inorder Traversal: ");
    Inorder(root);
    printf("\n");

    printf("Number of Nodes: %d\n", Count_Nodes(root));
    return 0;
}