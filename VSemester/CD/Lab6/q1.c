#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int curr = 0;
char str[100];

void S();
void A();
void Aprime();

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
	if(str[curr] == 'a')
	{
		curr++;
		return;
	}
	else if(str[curr] == '>')
	{
		curr++;
		return;
	}
	else if(str[curr] == '(')
	{
		curr++;
		A();

		if(str[curr] == ')')
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

void A()
{
	S();
	Aprime();
}

void Aprime()
{
	if(str[curr] == ',')
	{
		curr++;
		S();
		Aprime();
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