%{
	int count = 0;
%}

digit [0-9]
number {digit}+

%%
{number} {int n = atoi(yytext); printf("%x", n); if (n > 9) count++;}
%%

int yywrap() {return 1;}

int main() 
{
	printf("Enter a decimal number: ");
    yylex();
}