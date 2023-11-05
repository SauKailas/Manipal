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

const char *keywords[] = {"int", "char", "do", "while", "for", "if", "else", "switch",
								"case", "return", "break", "unsigned", "const"};
const char arithmetic_symbols[] = {"*"};
const char special_symbols[] = {'?', ';', ':', ','};

int isKeyword(const char *str)
{
	for(int i=0; i<sizeof(keywords)/sizeof(char*); i++)
		if(strcmp(keywords[i], str) == 0)
			return 1;
	return 0;
}

int charBelongsTo(char c, const char *arr)
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

void fillToken(struct token *tkn, char c, int row, int col, char *type)
{
	tkn->row = row;
	tkn->col = col;
	tkn->lexeme[0] = c;
	tkn->lexeme[1] = '\0';
	strcpy(tkn->type, type);
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
		if(charBelongsTo(c, special_symbols))
		{
			fillToken(&tkn, c, row, col, "SS");
			gotToken = 1;
			++col;
		}
		else if(charBelongsTo(c, arithmetic_symbols))
		{
			fillToken(&tkn, c, row, col, "ARITHMETIC OPERATOR");
			gotToken = 1;
			++col;
		}
		else if(c == '(')
		{
			fillToken(&tkn, c, row, col, "LB");
			gotToken = 1;
			++col;
		}
		else if(c == ')')
		{
			fillToken(&tkn, c, row, col, "RB");
			gotToken = 1;
			++col;
		}
		else if(c == '{')
		{
			fillToken(&tkn, c, row, col, "LC");
			gotToken = 1;
			++col;
		}
		else if(c == '}')
		{
			fillToken(&tkn, c, row, col, "RC");	
			gotToken = 1;
			++col;
		}
		else if(c == '+')
		{
			int d = fgetc(f1);

			if(d != '+')
			{
				fillToken(&tkn, c, row, col, "ARIHTMETIC OPERATOR");
				gotToken = 1;
				fseek(f1, -1, SEEK_CUR);
				++col;
			}
			else
			{
				fillToken(&tkn, c, row, col, "UNARY OPERATOR");
				strcpy(tkn.lexeme, "++");
				gotToken = 1;
				col += 2;
			}
		}
		else if(c == '-')
		{
			int d = fgetc(f1);

			if(d != '-')
			{
				fillToken(&tkn, c, row, col, "ARIHTMETIC OPERATOR");
				gotToken = 1;
				fseek(f1, -1, SEEK_CUR);
				++col;
			}
			else
			{
				fillToken(&tkn, c, row, col, "UNARY OPERATOR");
				strcpy(tkn.lexeme, "--");
				gotToken = 1;
				col += 2;
			}
		}
		else if(c == '=')
		{
			int d = fgetc(f1);

			if(d != '=')
			{
				fillToken(&tkn, c, row, col, "ASSIGNMENT OPERATOR");
				gotToken = 1;
				fseek(f1, -1, SEEK_CUR);
				++col;
			}
			else
			{
				fillToken(&tkn, c, row, col, "RELATIONAL OPERATOR");
				strcpy(tkn.lexeme, "==");
				gotToken = 1;
				col += 2;
			}
		}
		else if(isdigit(c))
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
			strcpy(tkn.type, "number");
			fseek(f1, -1, SEEK_CUR);
			gotToken = 1;
		}
		else if(c == '#')
		{
			while((c = fgetc(f1)) != EOF && c != '\n');
			newLine();
		}
		else if(c == '\n')
		{
			newLine();
		}
		else if(isspace(c))
		{
			++col;
		}
		else if(isalpha(c) || c == '_')
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
				strcpy(tkn.type, "keyword");
			else
				strcpy(tkn.type, "identifier");

			gotToken = 1;
		}
		else if(c == '"')
		{
			tkn.row = row;
			tkn.col = col;
			tkn.lexeme[0] = c;
			strcpy(tkn.type, "string literal");

			int k = 1;

			while((c = fgetc(f1)) != EOF && c != '"')
			{
				tkn.lexeme[k++] = c;
				col++;
			}

			tkn.lexeme[k++] = '"';
			tkn.lexeme[k] = '\0';
			gotToken = 1;
		}
		else if(c == '/')
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
			else if(c == '*')
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
		else if(c == '<' || c == '>' || c == '!')
		{
			fillToken(&tkn, c, row, col, "LOGICAL OPERATOR");
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
					strcpy(tkn.type, "RELATIONAL OPERATOR");

				fseek(f1, -1, SEEK_CUR);
			}

			gotToken = 1;
		}
		else if(c == '&' || c == '|')
		{
			int d = fgetc(f1);

			if(c == d)
			{
				tkn.row = row;
				tkn.col = col;
				col++;
				tkn.lexeme[0] = c;
				tkn.lexeme[1] = d;
				tkn.lexeme[2] = '\0';
				strcpy(tkn.type, "LOGICAL OPERATOR");
				gotToken = 1;
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

	struct token tkn;

	printf("Enter the filename to open for reading: ");
	scanf("%s", filename);

	f1 = fopen(filename, "r");

	if(f1 == NULL)
	{
		printf("Cannot open file %s!\n", filename);
		exit(0);
	}

	printf("\n\nTOKENS:\n\n");

	while((tkn = getNextToken(f1)).row != -1)
		printf("<%s, %d, %d>\n", tkn.type, tkn.row, tkn.col);

	fclose(f1);

	return 0;
}