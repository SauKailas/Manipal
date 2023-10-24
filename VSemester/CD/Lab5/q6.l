upper [A-Z]
space [ \t\n]

%%
[/][/][a-zA-z0-9]*	ECHO;
{upper}    {printf(yyout, yytext[0]+ 32);}
{space}    ECHO;
. ECHO;
%%

int yywrap()
{
	return 1;
}

int main()
{
	yyin=fopen("q6in.c","r");                            
	yyout=fopen("q6out.c","w");                        
    yylex();
    printf("Modifications Done!\n");

   	return 0;
}