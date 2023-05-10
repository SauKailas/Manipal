#include<stdio.h>

int size;
int hash_table[100];

void Init(){
    for(int i=0; i<size; i++)
        hash_table[i]=-1;
}

void Insert_Value(){
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);

    int key=value%size;

    if(hash_table[key]==-1)
    {
        hash_table[key]=value;
        return;
    }

    for(int i=key; i<size; i++)
    {
        if(hash_table[i]==-1)
        {
            hash_table[i]=value;
            return;
        }
    }

    for(int i=0; i<key-1; i++)
    {
        if(hash_table[i]==-1)
        {
            hash_table[i]=value;
            return;
        }
    }

    printf("Hash Table is FULL!\n");
}

void Display_Hash_Table(){
    printf("\nHash Table: ");
    for(int i=0; i<size; i++)
    {
        if(hash_table[i]==-1)
            printf("NULL ");
        else
            printf("%d  ", hash_table[i]);
    }
    printf("\n");
}

void Search_Value(){
    int value;
    printf("Enter value to search: ");
    scanf("%d", &value);

    int key=value%size;

    if(hash_table[key]==value)
    {
        printf("Key FOUND!\n");
        return;
    }
    else if(hash_table[key]==-1)
    {
        printf("Key NOT found!\n");
        return;
    }

    for(int i=key; i<size; i++)
        if(hash_table[i]==value)
        {
            printf("Key FOUND!\n");
            return;
        }
    
    for(int i=0; i<key-1; i++)
        if(hash_table[i]==value)
        {
            printf("Key FOUND!\n");
            return;
        }

    printf("Key NOT found!\n");
}

int main()
{
    printf("Enter size: ");
    scanf("%d", &size);
    Init();
    int ch;

    do{
        printf("Select an Option:\n");
        printf("1. Insert Value\n");
        printf("2. Display Hash Table\n");
        printf("3. Search Value\n");
        printf("4. Exit\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                Insert_Value();
                break;
            
            case 2:
                Display_Hash_Table();
                printf("\n");
                break;

            case 3: 
                Search_Value();
                break;
        }
    }while(ch!=4);

    return 0;
}