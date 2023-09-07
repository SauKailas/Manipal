// Construction of token generator. Each token has row number, column number, and token type.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct token
{
	int row, col;
	char lexeme[64];
	char type[20];
};

struct table_entry
{
	int sno;
	char lexeme_name[100];
	char dtype[100], ttype[100], retype[100];
	int no_args;
}Table[100];

static int row = 1, col = 1;
char buf[2048];
char dbuf[200];
static int ind = 1;

const char special_symbols[] = {'?', ';', ':', ','};
const char *keywords[] = {"const", "char", "int", "return", "for", "while", "do",
                          "switch", "if", "else", "unsigned", "case", "break"};
const char arithmetic_symbols[] = {"*"};
const char *datatypes[] = {"int", "double", "char", "float"};

int isKeyword(const char *str)
{
	for(int i=0; i<sizeof(keywords)/sizeof(char*); i++)
		if(strcmp(str, keywords[i]) == 0)
			return 1;
	return 0;
}

int isDatatype(const char *str)
{
	for(int i=0; i<sizeof(datatypes)/sizeof(char*); i++)
		if(strcmp(str, datatypes[i]) == 0)
			return 1;
	return 0;
}

int searchTable(const char *name)
{
	if(ind == 1)
		return 0;

	for(int i=0; i<ind; i++)
		if(strcmp(Table[i].lexeme_name, name) == 0)
			return 1;
	return 0;
}

void insertIntoTable(struct token *tkn, int no_args, const char *type)
{
	if(strcmp(type, "VARIABLE") == 0)
	{
		Table[ind-1].sno = ind;
		strcpy(Table[ind-1].lexeme_name, tkn->lexeme);
		strcpy(Table[ind-1].dtype, dbuf);
		strcpy(Table[ind-1].ttype, "VAR");
		++ind;
	}
	else if(strcmp(type, "FUNCTION") == 0)
	{
		Table[ind-1].sno = ind;
		strcpy(Table[ind-1].lexeme_name, tkn->lexeme);
		strcpy(Table[ind-1].retype, dbuf);
		strcpy(Table[ind-1].ttype, "FUNC");
		Table[ind-1].no_args = no_args;
		++ind;
	}
	else
		printf("Token CANNOT be Inserted!\n");
}

void printTable(int n)
{
	for(int i=0; i<n; i++)
	{
		if(strcmp(Table[i].ttype, "VAR") == 0)
			printf("%d\t%s\t\t%s\t\t-\t\t-\t\t%s\n", Table[i].sno, Table[i].lexeme_name, Table[i].dtype, Table[i].ttype);
		else if(strcmp(Table[i].ttype, "FUNC") == 0)
			 printf("%d\t%s\t\t-\t\t%s\t\t%d\t\tc%s\n", Table[i].sno, Table[i].lexeme_name, Table[i].retype, Table[i].no_args, Table[i].ttype);
	}
}

int isFuncName(FILE *f1, char c)
{
	int no_args = 0;

	if(c == '(')
	{
		char d;
		int chars = 0;

		while((d = fgetc(f1)) != EOF && d != ')')
		{
			if(d == ',')
				no_args++;
			chars++;
		}
		if(no_args != 0)
			no_args++;
		fseek(f1, (0-chars-1), SEEK_CUR);
	}
	else
	{
		no_args = -1;
		fseek(f1, 0, SEEK_CUR);
	}
	return no_args;
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
		else if(c == '-')
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
		else if(c == '=')
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
				fillToken(&tkn, c, row, col, "UNARY OPERATOR");
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
			strcpy(tkn.type, "NUMBER");
			gotToken = 1;
			fseek(f1, -1, SEEK_CUR);
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
			
			if(isKeyword(tkn.lexeme) == 0)
			{
				if(searchTable(tkn.lexeme) == 0)
				{
					int no_args = isFuncName(f1, c);
					if(no_args == -1)
						insertIntoTable(&tkn, no_args, "VARIABLE");
					else
						insertIntoTable(&tkn, no_args, "FUNCTION");
				}
				strcpy(tkn.lexeme, "ID");
			}
			else if(isDatatype(tkn.lexeme))
				strcpy(dbuf, tkn.lexeme);

			fseek(f1, -1, SEEK_CUR);
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
		else if(c == '"')
		{
			tkn.row = row;
			tkn.col = col;
			col++;
			tkn.lexeme[0] = c;
			strcpy(tkn.type, "STRING LITERAL");

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
		else if(c == '<' || c == '>' || c == '!')
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
		else if(c == '&' || c == '|')
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
				strcpy(tkn.type, "LOGICAL OPERATOR");
				gotToken = 1;
			}
			else
				fseek(f1, -1, SEEK_CUR);
			++col;
		}
		else
			col++;
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

	struct token tkn;

	printf("\n\nTOKENS:\n\n");

	while((tkn = getNextToken(f1)).row != -1)
		printf("<%s, %d, %d>\n", tkn.type, tkn.row, tkn.col);

	printf("\n\nTABLE:\n\n");

	printf("S. No. \tLexemeName \tDataType \tReturnType \tNoArgs \t\t TokenName\n");
	printTable(ind);

	fclose(f1);

	return 0;
}