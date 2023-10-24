#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "la.h"

FILE *f;
struct token t;

void Invalid(struct token tkn);
void Valid();
void ReturnType();
void Program();
int DataType(char *lx);
void Declarations();
void IdentifierList(struct token t);
void AssignStat(struct token t);

void Invalid(struct token tkn)
{
	printf("Error at row: %d column: %d for lexeme: %s\n", tkn.row, tkn.col, tkn.lexeme);
	printf("-----ERROR!-----\n\n");
	exit(0);
}

void Valid()
{
	printf("-----SUCCESS!-----\n\n");
	exit(0);
}

void ReturnType()
{
	t = getNextToken(f);
	if(strcmp(t.lexeme, "int"))
		return;
	else
		Invalid(t);
}

void Program()
{
	t = getNextToken(f);
	ReturnType();

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

int DataType(char *lx)
{
	if(strcmp(lx, "int") == 0 || strcmp(lx, "char") == 0)
		return 1;
	return 0;
}

void Declarations()
{
	t = getNextToken(f);

	if(DataType(t.lexeme))
	{
		t = getNextToken(f);
		IdentifierList(t);
		t = getNextToken(f);

		if(strcmp(t.lexeme, ";") == 0)
			Declarations();
		else
			Invalid(t);
	}
	else
		AssignStat(t);
}

void IdentifierList(struct token t)
{
	struct token tkn;

	if(strcmp(t.type, "identifier") == 0)
	{
		tkn = getNextToken(f);

		if(strcmp(tkn.lexeme, ",") == 0)
		{
			tkn = getNextToken(f);
			IdentifierList(tkn);
		}
		else if(strcmp(tkn.lexeme, ";") == 0)
		{
			fseek(f, -1, SEEK_CUR);
			return;
		}
		else
			Invalid(tkn);
	}
}

void AssignStat(struct token t)
{
	struct token tkn;

	if(strcmp(t.type, "identifier") == 0)
	{
		tkn = getNextToken(f);

		if(strcmp(tkn.lexeme, "=") == 0)
		{
			tkn = getNextToken(f);

			if(strcmp(tkn.type, "identifier") == 0 || strcmp(tkn.type, "number") == 0)
			{
				tkn = getNextToken(f);

				if(strcmp(tkn.lexeme, ";") == 0)
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