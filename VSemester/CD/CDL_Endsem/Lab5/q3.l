%{
	int pos_int = 0;
	int neg_int = 0;
	int pos_floats = 0;
	int neg_floats = 0;
%}

%%
[-][0-9]+[.][0-9]+ {neg_floats++;}
[0-9]+[.][0-9]+ {pos_floats++;}
[-][0-9]+ {neg_int++;}
[0-9]+ {pos_int++;}
%%

int yywrap()
{
	return 1;
}

int main()
{
	printf("Enter some numbers: ");
	yylex();

	printf("Positive Integers: %d\n", pos_int);
	printf("Negative Integers: %d\n", neg_int);
	printf("Positive Floats: %d\n", pos_floats);
	printf("Negative Floats: %d\n", neg_floats);

	return 0;
}