%{
	int vowels = 0;
	int consonants = 0;
%}

%%
[aeiouAEIOU] {vowels++;}
[a-zA-Z] {consonants++;}
%%

int yywrap()
{
	return 1;
}

int main()
{
	printf("Enter a text: ");
	yylex();

	printf("Number of Vowels: %d\n", vowels);
	printf("Number of Consonants: %d\n", consonants);

	return 0;
}