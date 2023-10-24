%{
	int words = 0;
	int chars = 0;
	int blanks = 0;
	int lines = 0;
%}

%%
[a-zA-Z]+ {words++; chars += strlen(yytext);}
\n {lines++;}
" " {blanks++;}		
%%

int yywrap()
{
	return 1;
}

int main()
{
	printf("Enter a text:\n");
	yylex();

	printf("\nWords: %d\n", words);
	printf("Characters: %d\n", chars);
	printf("Lines: %d\n", lines);
	printf("Blanks: %d\n", blanks);

	return 0;
}
