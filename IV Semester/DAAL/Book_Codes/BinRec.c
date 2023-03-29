#include<stdio.h>

int BinRec(int n){
	if(n==1)
		return 1;
	return 1+BinRec(n/2);
}

int main()
{
	int n;

	printf("Enter the value of n:\t");
	scanf("%d", &n);

	printf("Binary representation of %d requires %d bits\n", n, BinRec(n));
	return 0;
}