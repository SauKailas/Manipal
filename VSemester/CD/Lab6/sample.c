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

void E();
void T();
void Eprime();
void F();
void Tprime();

void E()
{
	T();
	Eprime();
}

void Eprime()
{
	if(str[curr] == '+')
	{
		curr++;
		T();
		Eprime();
	}
}

void T()
{
	F();
	Tprime();
}

void Tprime()
{
	if(str[curr] == '*')
	{
		curr++;
		F();
		Tprime();
	}
}

void F()
{
	if(str[curr] == '(')
	{
		curr++;
		E();
		if(str[curr] == ')')
		{
			curr++;
			return;
		}
		else
			Invalid();
	}
	else if(str[curr] == 'i')
	{
		curr++;
		return;
	}
	else
		Invalid();
}

int main()
{
	printf("Enter a string: ");
	scanf("%s", str);

	printf("\nString entered: %s\n", str);

	E();

	if(str[curr] == '$')
		Valid();
	else
		Invalid();
}