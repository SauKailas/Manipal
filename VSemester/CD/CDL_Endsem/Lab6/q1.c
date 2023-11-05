#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int curr;
char str[100];

void Valid()
{
	printf("-----SUCCESS!\n\n-----");
	exit(0);
}

void Invalid()
{
	printf("-----ERROR!\n\n-----");
	exit(0);
}

void S();
void T();
void Tprime();

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
		T();
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

void T()
{
	S();
	Tprime();
}

void Tprime()
{
	if(str[curr] == ',')
	{
		curr++;
		S();
		Tprime();
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