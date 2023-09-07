// Construction of token generator. Each token has row number, column number, and token type.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct token
{
	char lexeme[64];
	int row, col;
	char type[20];
};

static int row = 1, col = 1;

const char special_symbols[] = {'?', ';', ':', ','};
const char *keywords[] = {"const", "char", "int", "return", "for", "while", "do",
                          "switch", "if", "else", "unsigned", "case", "break"};
const char arithmetic_symbols[] = {"*"};

int isKeyword(const char *str)								// Checking if a string is a keyword
{
	for(int i=0; i<sizeof(keywords)/sizeof(char*); i++)
		if(strcmp(keywords[i], str) == 0)
			return 1;
	return 0;
}

int charBelongsTo(char c, const char *arr)					// Checking whether it belongs to special_symbols or arithmetic_symbols
{
	int len;

	if(arr == special_symbols)
		len = sizeof(special_symbols) / sizeof(char);
	else if(arr == arithmetic_symbols)
		len = sizeof(arithmetic_symbols) / sizeof(char);

	for(int i=0; i<len; i++)
		if(c == arr[i])
			return 1;
	return 0;
}

void fillToken(struct token *token, char c, int row, int col, char *type)		// Fill the attributes of the token structure
{
	token->row = row;
	token->col = col;
	token->lexeme[0] = c;
	token->lexeme[1] = '\0';
	strcpy(token->type, type);
}

void newLine()
{
	++row;
	col = 1;
}

struct token getNextToken(FILE *f1)
{
	int c;
	struct token tkn = {.row = -1};

	int gotToken = 0;

	while(gotToken == 0 && (c = fgetc(f1)) != EOF)
	{
		if(charBelongsTo(c, special_symbols))							// Special Symbol
		{
			fillToken(&tkn, c, row, col, "SS");
			gotToken = 1;
			++col;
		}
		else if(charBelongsTo(c, arithmetic_symbols))					// Arithmetic Operator
		{
			fillToken(&tkn, c, row, col, "ARITHMETIC OPERATOR");
			gotToken = 1;
			++col;
		}
		else if(c == '(')												// Left Parentheses
		{
			fillToken(&tkn, c, row, col, "LB");
			gotToken = 1;
			++col;
		}
		else if(c == ')')												// Right Parentheses
		{
			fillToken(&tkn, c, row, col, "RB");
			gotToken = 1;
			++col;
		}
		else if(c == '{')												// Left Curly Brace
		{
			fillToken(&tkn, c, row, col, "LC");
			gotToken = 1;
			++col;
		}
		else if(c == '}')												// Right Curly Brace
		{
			fillToken(&tkn, c, row, col, "RC");
			gotToken = 1;
			++col;
		}
		else if(c == '+')												// + or ++ 
		{
			int d = fgetc(f1);

			if(d != '+')
			{
				fillToken(&tkn, c, row, col, "ARITHMETIC OPERATOR");
				gotToken = 1;
				++col;
				fseek(f1, -1, SEEK_CUR);
			}
			else
			{
				fillToken(&tkn, c, row, col, "UNARY OPERATOR");
				strcpy(tkn.lexeme, "++");
				gotToken = 1;
				col += 2;
			}
		}
		else if(c == '-')												// - or --
		{
			int d = fgetc(f1);

			if(d != '-')
			{
				fillToken(&tkn, c, row, col, "ARITHMETIC OPERATOR");
				gotToken = 1;
				++col;
				fseek(f1, -1, SEEK_CUR);
			}
			else
			{
				fillToken(&tkn, c, row, col, "UNARY OPERATOR");
				strcpy(tkn.lexeme, "--");
				gotToken = 1;
				col += 2;
			}
		}
		else if(c == '=')												// = or ==
		{
			int d = fgetc(f1);

			if(d != '=')
			{
				fillToken(&tkn, c, row, col, "ASSIGNMENT OPERATOR");
				gotToken = 1;
				++col;
				fseek(f1, -1, SEEK_CUR);
			}
			else
			{
				fillToken(&tkn, c, row, col, "RELATIONAL OPERATOR");
				strcpy(tkn.lexeme, "==");
				gotToken = 1;
				col += 2;
			}
		}
		else if(isdigit(c))												// NUMBER
		{
			tkn.row = row;
			tkn.col = col;
			col++;
			tkn.lexeme[0] = c;

			int k = 1;

			while((c = fgetc(f1)) != EOF && isdigit(c))
			{
				tkn.lexeme[k++] = c;
				col++;
			}

			tkn.lexeme[k] = '\0';
			gotToken = 1;
			strcpy(tkn.type, "NUMBER");
			fseek(f1, -1, SEEK_CUR);
		}
		else if(c == '#')												// #. Skip all preprocessor directives
		{
			while((c = fgetc(f1)) != EOF && c != '\n');
			newLine();
		}
		else if(c == '\n')												// New Line
		{
			newLine();
		}
		else if(isspace(c))												// Space
		{
			++col;
		}
		else if(isalpha(c) || c == '_')									// Alphabet
		{
			tkn.row = row;
			tkn.col = col;
			col++;
			tkn.lexeme[0] = c;

			int k = 1;

			while((c = fgetc(f1)) != EOF && isalnum(c))
			{
				tkn.lexeme[k++] = c;
				col++;
			}

			tkn.lexeme[k] = '\0';
			fseek(f1, -1, SEEK_CUR);

			if(isKeyword(tkn.lexeme))
				strcpy(tkn.type, "KEYWORD");
			else
				strcpy(tkn.type, "IDENTIFIER");

			gotToken = 1;
		}	
		else if(c == '/')												// / or // or /*
		{
			int d = fgetc(f1);
			++col;

			if(d == '/')
			{
				while((c = fgetc(f1)) != EOF && c != '\n')
					col++;

				if(c == '\n')
					newLine();
			}
			else if(d == '*')
			{
				do{
					if(d == '\n')
						newLine();

					while((c = fgetc(f1)) != EOF && c != '*')
					{
						col++;

						if(c == '\n')
							newLine();
					}
					++col;
				}while((d = fgetc(f1)) != EOF && d != '/' && (++col));
				++col;
			}
			else
			{
				--col;
				fillToken(&tkn, c, row, col, "ARITHMETIC OPERATOR");
				gotToken = 1;
				fseek(f1, -1, SEEK_CUR);
			}
		}	
		else if(c == '"')												// Double Quotes
		{
			tkn.row = row;
			tkn.col = col;
			tkn.lexeme[0] = c;
			strcpy(tkn.type, "STRING LITERAL");

			int k = 1;

			while((c = fgetc(f1)) != EOF && c != '"')
			{
				tkn.lexeme[k++] = c;
				++col;
			}

			tkn.lexeme[k++] = '"';
			tkn.lexeme[k] = '\0';
			gotToken = 1;
		}
		else if(c == '<' || c == '>' || c == '!')						// Relational Operators
		{
			fillToken(&tkn, c, row, col, "RELATIONAL OPERATOR");
			++col;

			int d = fgetc(f1);

			if(d == '=')
			{
				strcat(tkn.lexeme, "=");
				++col;
			}
			else
			{
				if(d == '!')
					strcpy(tkn.type, "LOGICAL OPERATOR");

				fseek(f1, -1, SEEK_CUR);
			}

			gotToken = 1;
		}
		else if(c == '&' || c == '|')									// Logical Operators
		{
			int d = fgetc(f1);

			if(c == d)
			{
				tkn.row = row;
				tkn.col = col;
				++col;
				tkn.lexeme[0] = c;
				tkn.lexeme[1] = d;
				tkn.lexeme[2] = '\0';
				gotToken = 1;
				strcpy(tkn.type, "LOGICAL OPERATOR");
			}
			else
				fseek(f1, -1, SEEK_CUR);
			++col;
		}
		else
			++col;
	}

	return tkn;
}

int main()
{
	FILE *f1;
	char filename[100];

	printf("Enter the filename to open for reading:\n");
	scanf("%s", filename);

	f1 = fopen(filename, "r");

	if(f1 == NULL)
	{
		printf("Cannot open file!\n");
		exit(0);
	}

	printf("\n\nTOKENS:\n\n");

	struct token tkn;

	while((tkn = getNextToken(f1)).row != -1)
		printf("<%s, %d, %d>\n", tkn.type, tkn.row, tkn.col);

	fclose(f1);

	return 0;
}