#include<stdio.h>
#include<string.h>

int opcount=0;

int String_Match(char T[100], char P[100]){

	for(int i=0; i<strlen(T)-strlen(P)+1; i++)
	{
		int j=0;
		opcount++;
		while(j<strlen(P) && P[j]==T[i+j])
			j++;
		if(j==strlen(P))
			return i;
	}
	return -1;
}

int main()
{
	char T[100], P[100];

	printf("Enter a text:\n");
	gets(T);

	printf("Enter a pattern:\n");
	gets(P);

	int res=String_Match(T, P);

	printf("The operation count is %d\n", opcount);

	if(res==-1)
		printf("The pattern is not found!\n");
	else
		printf("The index of pattern in text is %d\n", res);

	return 0;
}