%{
	int pos_int = 0;
	int neg_int = 0;
	int pos_float = 0;
	int neg_float = 0;
%}

%%
[-][0-9]+[.][0-9]+ {neg_float++;}
[0-9]+[.][0-9] {pos_float++;}
[-][0-9]+ {neg_int++;}	
[0-9]+ {pos_int++;}
%%

int yywrap()
{
	return 1;
}

int main()
{
	printf("Enter some numbers:\n");
	yylex();

	printf("\nPositive Integers: %d\n", pos_int);
	printf("Negative Integers: %d\n", neg_int);
	printf("Positive Floats: %d\n", pos_float);
	printf("Negative Floats: %d\n", neg_float);

	return 0;
}
