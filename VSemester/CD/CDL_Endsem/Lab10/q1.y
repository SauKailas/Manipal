%{
    #include<stdio.h>
    #include<stdlib.h>
    int yylex();
    int yyerror();
%}
%token INT ID SC CM NL CHAR EQ NUM
%%
stmt:DC NL
    |DC AS NL
;
DC : DT IDL SC DC { printf("\nValid declaration statement!\n"); exit(0);}
    |
;
DT: INT
    |
    CHAR
    ;
IDL: ID
    |ID CM IDL 
AS: ID EQ ID SC
    |ID EQ NUM SC
;
%%
int yyerror(char *msg)
{
    printf("Invalid declaration statement!\n");
    exit(0);
}
void main ()
{
    printf("Enter the declaration statement:\n");
    yyparse();
}

 