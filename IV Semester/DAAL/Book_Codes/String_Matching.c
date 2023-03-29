#include<stdio.h>
#include<string.h>

int String_Matching(char t[], char p[]){

	for(int i=0; i<=strlen(t)-strlen(p); i++)
	{
		int j=0;
		while(j<strlen(p) && t[i+j]==p[j])
			j++;
		if(j==strlen(p))
			return i;
	}
	return -1;
}

int main()
{
	char text[100], pattern[100];

	printf("Enter a text:\t");
	gets(text);

	printf("Enter a pattern:\t");
	gets(pattern);

	int val=String_Matching(text, pattern);

	if(val>=0)
		printf("Pattern found at index %d!\n", val);
	else
		printf("Pattern not found!\n");
	
	return 0;
}