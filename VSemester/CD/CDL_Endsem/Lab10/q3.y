%{
    #include<stdio.h>
    #include<stdlib.h>
    int yylex();
    int yyerror();
%}
%token NUMBER ID NL
%left '+' '-'
%left '*' '/'

%%
E : T {
            printf("Result = %d\n", $$);
            return 0;
       }
 
T : 
    T '+' T { $$ = $1+$3; }
    | T '-' T { $$ = $1-$3; }
    | T '*' T { $$ = $1*$3; }
    | T '/' T { $$ = $1/$3; }
    | '-' NUMBER { $$ = -$2; }
    | '-' ID { $$ = -$2; }
    | NUMBER { $$ = $1; }
    | ID { $$ = $1; };
%%
int yyerror(char *msg)
{
printf("Invalid Expression\n");
exit(0);
}

int main() {
    printf("Enter the expression\n");
    yyparse();
}
 
