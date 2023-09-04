#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int curr = 0;
char str[100];

void S();
void U();
void V();
void W();

void Invalid()
{
	printf("\n--------ERROR!--------\n");
	exit(0);
}

void Valid()
{
	printf("\n--------SUCCESS!--------\n");
	exit(0);
}

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

	S();

	if(str[curr] == '$')
		Valid();
	else
	{
		printf("%c\n", str[curr]);
		Invalid();
	}

	return 0;
}