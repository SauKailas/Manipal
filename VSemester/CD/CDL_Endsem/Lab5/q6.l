%{

%}

%%
"//"[A-Za-z" "]+\n {fprintf(yyout, "%s", yytext);}
"/*"[A-Za-z" "]+"*/" {fprintf(yyout, "%s", yytext);}
[A-Z] {fprintf(yyout, "%c", yytext[0] + 32);}
. ECHO;
%%

int yywrap()
{
	return 1;
}

int main()
{
	yyin = fopen("q6in.c", "r");
	yyout = fopen("q6out.c", "w+");
	yylex();

	printf("Modifications Done Successfully!\n");

	return 0;
}