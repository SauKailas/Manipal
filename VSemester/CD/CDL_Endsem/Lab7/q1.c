#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "la.h"

FILE *f;
struct token t;

void Invalid(struct token tkn);
void Valid();
void Program();
int Datatype(char *lx);
void Declarations();
void Identifier_List();
void Identifier_List_Prime();
void Assign_Stat();
void Assign_Stat_Prime();
void Assign_Stat_Prime_Prime();

void Invalid(struct token tkn)
{
	printf("Error at row %d column %d for lexeme %s!\n", tkn.row, tkn.col, tkn.lexeme);
	printf("-----ERROR!-----\n\n");
	exit(0);
}

void Valid()
{
	printf("-----SUCCESS!-----\n\n");
	exit(0);
}

void Program()
{
	t = getNextToken(f);

	if(strcmp(t.lexeme, "main") == 0)
	{
		t = getNextToken(f);

		if(strcmp(t.lexeme, "(") == 0)
		{
			t = getNextToken(f);

			if(strcmp(t.lexeme, ")") == 0)
			{
				t = getNextToken(f);

				if(strcmp(t.lexeme, "{") == 0)
				{
					Declarations();
					Assign_Stat();
					t = getNextToken(f);

					if(strcmp(t.lexeme, "}") == 0)
						return;
					else
						Invalid(t);
				}
				else
					Invalid(t);
			}
			else
				Invalid(t);
		}
		else
			Invalid(t);
	}
	else
		Invalid(t);
}

int Datatype(char *lx)
{
	if(strcmp(lx, "int") == 0 || strcmp(lx, "char") == 0)
		return 1;
	return 0;
}

void Declarations()
{
	t = getNextToken(f);
	int len = strlen(t.lexeme);

	if(strcmp(t.type, "identifier") == 0)
	{
		fseek(f, -len, SEEK_CUR);
		return;
	}
	else if(Datatype(t.lexeme))
	{
		Identifier_List();
		t = getNextToken(f);

		if(strcmp(t.lexeme, ";") == 0)
			Declarations();
		else
			Invalid(t);
	}
	else
		Invalid(t);
}

void Identifier_List()
{
	t = getNextToken(f);

	if(strcmp(t.type, "identifier") == 0)
		Identifier_List_Prime();
	else
		Invalid(t);
}

void Identifier_List_Prime()
{
	t = getNextToken(f);
	int len = strlen(t.lexeme);

	if(strcmp(t.lexeme, ";") == 0)
	{
		fseek(f, -len, SEEK_CUR);
		return;
	}	
	else if(strcmp(t.lexeme, ",") == 0)
		Identifier_List();
	else
		Invalid(t);
}

void Assign_Stat()
{
	t = getNextToken(f);

	if(strcmp(t.type, "identifier") == 0)
		Assign_Stat_Prime();
	else
		Invalid(t);
}

void Assign_Stat_Prime()
{
	t = getNextToken(f);

	if(strcmp(t.lexeme, "=") == 0)
		Assign_Stat_Prime_Prime();
	else
		Invalid(t);
}

void Assign_Stat_Prime_Prime()
{
	t = getNextToken(f);

	if(strcmp(t.type, "identifier") == 0 || strcmp(t.type, "number") == 0)
	{
		t = getNextToken(f);

		if(strcmp(t.lexeme, ";") == 0)
			return;
		else
			Invalid(t);
	}
	else
		Invalid(t);
}

int main()
{
	char filename[100];

	printf("Enter the filename to open for reading: ");
	scanf("%s", filename);

	f = fopen(filename, "r");

	if(f == NULL)
	{
		printf("Cannot open file %s!\n", filename);
		exit(0);
	}

	Program();
	Valid();
}