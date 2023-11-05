%{
	int printfs = 0;
	int scanfs = 0;
%}

%%
"printf" {printfs++; fprintf(yyout, "WRITE");}
"scanf" {scanfs++; fprintf(yyout, "READ");}
%%

int yywrap()
{
	return 1;
}

int main()
{
	yyin = fopen("q4in.c", "r");
	yyout = fopen("q4out.c", "w+");
	yylex();

	printf("Number of printfs: %d\n", printfs);
	printf("Number of scanfs: %d\n", scanfs);
	printf("Modifications Done Successfully!\n");

	return 0;
}