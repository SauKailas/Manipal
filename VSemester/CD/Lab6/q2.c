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
void U();
void V();
void W();

void S()
{
	U();
	V();
	W();
}

void U()
{
	if(str[curr] == '(')
	{
		curr++;
		S();
		if(str[curr] == ')')
		{
			curr++;
			return;
		}
		else
			Invalid();
	}
	else if(str[curr] == 'a')
	{
		curr++;
		S();
		if(str[curr] == 'b')
		{
			curr++;
			return;
		}
		else
			Invalid();
	}
	else if(str[curr] == 'd')
	{
		curr++;
		return;
	}
	else
		Invalid();
}

void V()
{
	if(str[curr] == 'a')
	{
		curr++;
		V();
	}
}

void W()
{
	if(str[curr] == 'c')
	{
		curr++;
		W();
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