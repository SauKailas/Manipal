#include<stdio.h>

int Counting_Binary(int n){
	int count=1;
	
	while(n>1)
	{
		count++;
		n/=2;
	}	
	return count;
}

int main()
{
	int n;

	printf("Enter the value of n:\t");
	scanf("%d", &n);

	printf("Binary digits is %d\n", Counting_Binary(n));

	return 0;
}