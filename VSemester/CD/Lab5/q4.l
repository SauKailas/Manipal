%{
	int printfs = 0;
	int scanfs = 0;
%}

%%
	"scanf"	{scanfs++; printf(yyout,"READ");}          
	"printf" {printfs++; printf(yyout,"WRITE");}            
%%

int yywrap()
{
	return 1;
}

int main()
{
	yyin=fopen("q4in.c","r");                            
	yyout=fopen("q4out.c","w");                        
	yylex();

	printf("Modifications Done!\n");
	printf("Number of scanfs = %d\n", scanfs);
	printf("Number of printfs = %d\n", printfs);

	return 0;
}