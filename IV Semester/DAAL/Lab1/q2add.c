#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *Push(struct node *start){
	struct node *new_node;
	new_node=(struct node*)malloc(sizeof(struct node));
	int data;

	printf("Enter the data: \t");
	scanf("%d", &data);
	new_node->data=data;

	if(start==NULL)
	{
		new_node->next=new_node->prev=new_node;
		return new_node;
	}

	struct node *ptr=start;
	while(ptr->next!=start)
		ptr=ptr->next;
	ptr->next->prev=new_node;
	new_node->next=ptr->next;
	ptr->next=new_node;
	new_node->prev=ptr;
	return start;
}

struct node *Pop(struct node *start){
	if(start==NULL)
	{
		printf("List is EMPTY!\n");
		return start;
	}

	struct node *ptr=start, *preptr;
	while(ptr->next!=start)
	{
		preptr=ptr;
		ptr=ptr->next;
	}

	preptr->next=ptr->next;
	ptr->next->prev=preptr;
	printf("Popped %d!\n", ptr->data);
	free(ptr);
	return start;
}

struct node *Display(struct node *start){
	if(start==NULL)
	{
		printf("List is EMPTY!\n");
		return start;
	}

	struct node *ptr=start;
	while(ptr->next!=start)
	{
		printf("%d<->", ptr->data);
		ptr=ptr->next;
	}
	printf("%d<->\n", ptr->data);

	return start;
}

int main()
{
	struct node *start=NULL;
	int opt;

	do{
		printf("\nSelect an option:\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				start=Push(start);
				break;
			case 2:
				start=Pop(start);
				break;
			case 3:
				start=Display(start);
				break;
		}
	}while(opt!=4);

	return 0;
}