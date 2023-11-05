%{
	int words = 0;
	int chars = 0;
	int blanks = 0;
	int lines = 0;
%}

%%
[a-zA-Z]+ {words++; chars += strlen(yytext);}
" " {blanks++;}
"\n" {lines++;}
%%

int yywrap()
{
	return 1;
}

int main()
{
	printf("Enter a text:\n");
	yylex();

	printf("Number of Words: %d\n", words);
	printf("Number of Characters: %d\n", chars);
	printf("Number of Blanks: %d\n", blanks);
	printf("Number of Lines: %d\n", lines);

	return 0;
}