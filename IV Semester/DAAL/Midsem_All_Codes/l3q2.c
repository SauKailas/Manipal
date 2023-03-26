/*
Write a program to implement brute-force string matching. Analyze its time efficiency.

ALGORITHM:
Input: Array of characters (text) T of size n and array of characters (pattern) P of size m.
Output: Index of first character in T that starts P or -1 if P is not found.

for i<-0 to n-m do
	j<-0
	while j<m and T[i+j]=P[j] do
		j<-j+1
	if j=m return i
return -1
*/

#include<stdio.h>
#include<string.h>

int String_Matching(char T[50], char P[50]){

	for(int i=0; i<=strlen(T)-strlen(P); i++)
	{
		int m=0;
		for(int j=0; j<strlen(P); j++)
		{
			if(T[i+j]==P[j])
				m++;
			else
				break;
		}

		if(m==strlen(P))
			return i;
	}
	return -1;
}

int main()
{
	int T[100], P[100];

	printf("Enter the text: ");
	gets(T);

	printf("Enter the pattern: ");
	gets(P);

	int val=String_Matching(T, P);

	if(val==-1)
		printf("Pattern NOT found!\n");
	else
		printf("Pattern FOUND at index %d!\n", val);

	return 0;
}