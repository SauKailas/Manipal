#include<stdio.h>

int Fibonacci(int n)
{
	if(n==0 || n==1)
		return n;
	return Fibonacci(n-1)+Fibonacci(n-2);
}

int main()
{
	int n;

	printf("Enter the value of n:\t");
	scanf("%d", &n);

	printf("The %dth Fibonacci Number is %d\n", n, Fibonacci(n));
	return 0;
}