#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int main()
{
	int a = 30;
	float b = 29.5;
	char c = 'K';
	char str[] = "Saurabh Kailas";
	printf("a = %d\nb = %f\nc = %c\nstr = %s\nHexadecimal for a = %x\n", a, b, c, str, a);

	errno = EPERM;
    printf("Error Access Number : %m\n");

	return 0;
}