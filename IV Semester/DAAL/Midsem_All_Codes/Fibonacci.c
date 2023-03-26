/*Find the nth Fibonacci number using recursion*/

#include<stdio.h>

int Fibonacci(int n){
	if(n<=1)
		return n;
	return Fibonacci(n-1)+Fibonacci(n-2);
}

int main()
{
	int n;
	printf("Enter the value of n: ");
	scanf("%d", &n);

	printf("The %dth Fibonacci Number is %d\n", n, Fibonacci(n-1));
	return 0;
}