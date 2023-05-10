#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int size;
struct node *Hash_Table[100];

void Init(){
    for(int i=0; i<size; i++)
        Hash_Table[i]=NULL;
}

void Insert_Node(){
    int data;
    printf("Enter data to insert: ");
    scanf("%d", &data);

    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;

    int hash_value=data%size;

    if(!Hash_Table[hash_value])
        Hash_Table[hash_value]=new_node;
    else
    {
        struct node *ptr=Hash_Table[hash_value];
        while(ptr->next)
            ptr=ptr->next;
        ptr->next=new_node;
    }
}

void Display_Hash_Table(){
    printf("\n");
    struct node *ptr;

    for(int i=0; i<size; i++)
    {
        printf("List %d: ", i);
        ptr=Hash_Table[i];

        while(ptr)
        {
            printf("%d->", ptr->data);
            ptr=ptr->next;
        }
        printf("NULL\n");
    }
    printf("\n");
}

void Search(){
    int value;
    printf("Enter value to search: ");
    scanf("%d", &value);

    int key=value%size;

    struct node *ptr=Hash_Table[key];

    while(ptr)
    {
        if(ptr->data==value)
        {
            printf("Key FOUND!\n");
            return;
        }
    }
    printf("Key NOT found!\n");
}

int main()
{
    printf("Enter the size: ");
    scanf("%d", &size);
    Init();
    int ch;

    do{
        printf("Select an Option:\n");
        printf("1. Insert Node\n");
        printf("2. Display Hash Table\n");
        printf("3. Search an Element\n");
        printf("4. Exit\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                Insert_Node();
                break;
            
            case 2:
                Display_Hash_Table();
                break;

            case 3:
                Search();
                break;
        }
    }while(ch!=4);

    return 0;
}