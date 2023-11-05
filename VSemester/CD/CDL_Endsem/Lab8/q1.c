#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "la.h"

FILE *f;
struct token t;

void Invalid(struct token tkn, char *expected);
void Valid();
void Program();
int Datatype(char *lx);
void Declarations();
void Identifier_List();
void Identifier_List_Prime();
void Identifier_List_Prime_Prime();
void Statement_List();
void Statement();
void Assign_Stat();
void Expn();
void Eprime();
void Simple_Expn();
void Seprime();
void Term();
void Tprime();
void Factor();
void Relop();
void Addop();
void Mulop();

void Invalid(struct token tkn, char *expected)
{
    printf("Expected %s at row %d and column %d!\n", expected, tkn.row, tkn.col);
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
                    Statement_List();   
                    t = getNextToken(f);

                    if(strcmp(t.lexeme, "}") == 0)
                        return;
                    else
                        Invalid(t, "}");
                }
                else
                    Invalid(t, "{");
            }
            else
                Invalid(t, ")");
        }
        else
            Invalid(t, "(");
    }
    else
        Invalid(t, "main");
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
    else if(strcmp(t.lexeme, "}") == 0)
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
            Invalid(t, ";");
    }
    else
        Invalid(t, "datatype");
}

void Identifier_List()
{
    t = getNextToken(f);

    if(strcmp(t.type, "identifier") == 0)
        Identifier_List_Prime();
    else
        Invalid(t, "identifier");
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
    else if(strcmp(t.lexeme, "[") == 0)
    {
        t = getNextToken(f);

        if(strcmp(t.type, "number") == 0)
        {
            t = getNextToken(f);

            if(strcmp(t.lexeme, "]") == 0)
                Identifier_List_Prime_Prime();
            else
                Invalid(t, "]");
        }
        else
            Invalid(t, "number");
    }
    else
        Invalid(t, ", or [");
}

void Identifier_List_Prime_Prime()
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
        Invalid(t, ",");
}

void Statement_List()
{
    t = getNextToken(f);
    int len = strlen(t.lexeme);

    if(strcmp(t.lexeme, "}") == 0)
    {
        fseek(f, -len, SEEK_CUR);
        return;
    }
    else
        fseek(f, -len, SEEK_CUR);

    Statement();
    Statement_List();
}

void Statement()
{
    Assign_Stat();
    t = getNextToken(f);

    if(strcmp(t.lexeme, ";") == 0)
        return;
    else
        Invalid(t, ";");
}

void Assign_Stat()
{
    t = getNextToken(f);

    if(strcmp(t.type, "identifier") == 0)
    {
        t = getNextToken(f);

        if(strcmp(t.lexeme, "=") == 0)
            Expn();
        else
            Invalid(t, "=");
    }
    else
        Invalid(t, "identifier");
}

void Expn()
{
    Simple_Expn();
    Eprime();
}

void Eprime()
{
    t = getNextToken(f);
    int len = strlen(t.lexeme);

    if(strcmp(t.lexeme, ";") == 0)
    {
        fseek(f, -len, SEEK_CUR);
        return;
    }
    else
        fseek(f, -len, SEEK_CUR);

    Relop();
    Simple_Expn();
}

void Simple_Expn()
{
    Term();
    Seprime();
}

void Seprime()
{
    t = getNextToken(f);
    int len = strlen(t.lexeme);

    if(strcmp(t.lexeme, ";") == 0)
    {
        fseek(f, -len, SEEK_CUR);
        return;
    }
    else if(strcmp(t.lexeme, "==") == 0)
    {
        fseek(f, -len, SEEK_CUR);
        return;
    }
    else if(strcmp(t.lexeme, "!=") == 0)
    {
        fseek(f, -len, SEEK_CUR);
        return;
    }
    else if(strcmp(t.lexeme, "<=") == 0)
    {
        fseek(f, -len, SEEK_CUR);
        return;
    }
    else if(strcmp(t.lexeme, ">=") == 0)
    {
        fseek(f, -len, SEEK_CUR);
        return;
    }
    else if(strcmp(t.lexeme, "<") == 0)
    {
        fseek(f, -len, SEEK_CUR);
        return;
    }
    else if(strcmp(t.lexeme, ">") == 0)
    {
        fseek(f, -len, SEEK_CUR);
        return;
    }
    else
        fseek(f, -len, SEEK_CUR);

    Addop();
    Term();
    Seprime();
}

void Term()
{
    Factor();
    Tprime();
}

void Tprime()
{
    t = getNextToken(f);
    int len = strlen(t.lexeme);

    if(strcmp(t.lexeme, ";") == 0)
    {
        fseek(f, -len, SEEK_CUR);
        return;
    }
    else if(strcmp(t.lexeme, "+") == 0)
    {
        fseek(f, -len, SEEK_CUR);
        return;
    }
    else if(strcmp(t.lexeme, "-") == 0)
    {
        fseek(f, -len, SEEK_CUR);
        return;
    }
    else if(strcmp(t.lexeme, "==") == 0)
    {
        fseek(f, -len, SEEK_CUR);
        return;
    }
    else if(strcmp(t.lexeme, "!=") == 0)
    {
        fseek(f, -len, SEEK_CUR);
        return;
    }
    else if(strcmp(t.lexeme, "<=") == 0)
    {
        fseek(f, -len, SEEK_CUR);
        return;
    }
    else if(strcmp(t.lexeme, ">=") == 0)
    {
        fseek(f, -len, SEEK_CUR);
        return;
    }
    else if(strcmp(t.lexeme, ">") == 0)
    {
        fseek(f, -len, SEEK_CUR);
        return;
    }
    else if(strcmp(t.lexeme, "<") == 0)
    {
        fseek(f, -len, SEEK_CUR);
        return;
    }
    else
        fseek(f, -len, SEEK_CUR);

    Mulop();
    Factor();
    Tprime();
}

void Factor()
{
    t = getNextToken(f);

    if(strcmp(t.type, "identifier") == 0 || strcmp(t.type, "number") == 0)
        return;
    else
        Invalid(t, "identifier or number");
}

void Relop()
{
    t = getNextToken(f);

    if(strcmp(t.lexeme, "==") == 0)
        return;
    else if(strcmp(t.lexeme, "!=") == 0)
        return;
    else if(strcmp(t.lexeme, "<=") == 0)
        return;
    else if(strcmp(t.lexeme, ">=") == 0)
        return;
    else if(strcmp(t.lexeme, ">") == 0)
        return;
    else if(strcmp(t.lexeme, "<") == 0)
        return;
    else
        Invalid(t, "relop");
}

void Addop()
{
    t = getNextToken(f);

    if(strcmp(t.lexeme, "+") == 0)
        return;
    else if(strcmp(t.lexeme, "-") == 0)
        return;
    else
        Invalid(t, "addop");
}

void Mulop()
{
    t = getNextToken(f);

    if(strcmp(t.lexeme, "*") == 0)
        return;
    else if(strcmp(t.lexeme, "/") == 0)
        return;
    else if(strcmp(t.lexeme, "%") == 0)
        return;
    else
        Invalid(t, "mulop");
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