#include<stdio.h>

int Factorial(int n){
	if(n==0)
		return 1;
	return n*Factorial(n-1);
}

int main()
{
	int n;

	printf("Enter the value of n:\t");
	scanf("%d", &n);

	printf("The factorial of %d is %d\n", n, Factorial(n));
	return 0;
}