#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int curr = 0;
char str[100];

void Valid()
{
	printf("-----SUCCESS!-----\n\n");
	exit(0);
}

void Invalid()
{
	printf("-----ERROR!-----\n\n");
	exit(0);
}

void S();
void A();
void Aprime();
void B();

void S()
{
	if(str[curr] == 'a')
	{
		curr++;
		A();
		if(str[curr] == 'c')
		{
			curr++;
			B();
			if(str[curr] == 'e')
			{
				curr++;
				return;
			}
			else
				Invalid();
		}
		else
			Invalid();
	}
	else 
		Invalid();
}

void A()
{
	if(str[curr] == 'b')
	{
		curr++;
		Aprime();
	}
}

void Aprime()
{
	if(str[curr] == 'b')
	{
		curr++;
		Aprime();
	}
}

void B()
{
	if(str[curr] == 'd')
	{
		curr++;
		return;
	}
}

int main()
{
	printf("Enter a string: ");
	scanf("%s", str);

	printf("\nString entered: %s\n", str);

	S();

	if(str[curr] == '$')
		Valid();
	else
		Invalid();
}