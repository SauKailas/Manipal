#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int curr = 0;
char str[100];

void S();
void A();
void Aprime();
void B();

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
		}
	}
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