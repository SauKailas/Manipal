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
	printf("Enter a word: ");
	yylex();

	printf("Vowels: %d\n", vowels);
	printf("Consonants: %d\n", consonants);

	return 0;
}
