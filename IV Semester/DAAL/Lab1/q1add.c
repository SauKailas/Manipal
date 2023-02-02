#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *Insert(struct node *start){
	struct node *new_node;
	new_node=(struct node*)malloc(sizeof(struct node));
	int data;

	printf("Enter the data: \t");
	scanf("%d", &data);
	new_node->data=data;

	if(start==NULL)
	{
		new_node->next=NULL;
		return new_node;
	}

	new_node->next=start;
	start=new_node;
	return start;
}

int Search(struct node *start){
	struct node *ptr;
	int data;
	printf("Enter data to search: \t");
	scanf("%d", &data);

	if(start==NULL)
		return 0;

	ptr=start;
	while(ptr)
	{
		if(ptr->data==data)
			return 1;
		ptr=ptr->next;
	}
	return 0;
}

void Display(struct node *start){
	if(start==NULL)
	{
		printf("List is EMPTY!\n");
		return;
	}

	struct node *ptr=start;
	while(ptr->next!=NULL)
	{
		printf("%d->", ptr->data);
		ptr=ptr->next;
	}
	printf("%d\n", ptr->data);
}

int main()
{
	struct node *start=NULL;
	int opt;

	do{
		printf("\nSelect an option:\n");
		printf("1. Insert Node\n");
		printf("2. Search a Value\n");
		printf("3. Display List\n");
		printf("4. Exit\n");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				start=Insert(start);
				break;
			case 2:
				if(Search(start))
					printf("Element Found!\n");
				else
					printf("Element not Found!\n");
				break;
			case 3:
				Display(start);
				break;
		}
	}while(opt!=4);

	return 0;
}