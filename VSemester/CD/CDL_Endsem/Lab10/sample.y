%{
	#include<stdio.h>
	#include<stdlib.h>	
%}

%token NUMBER ID NL
%token PLUS STAR

%%
stmt : expn NL {printf("Valid Expression!\n"); exit(0);} ;
expn : expn PLUS term | term ;
term : term STAR factor | factor ;
factor : ID | NUMBER ; 
%%

int yerror(char *msg)
{
	printf("Invalid Expression!\n");
	exit(0);
}

int main()
{
	printf("Enter an expression:\n");
	yyparse();

	return 0;
}