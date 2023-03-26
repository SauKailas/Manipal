/*
Write a program to find GCD using middle school method and analyze its time efficiency.

ALGORITHM:
Step 1: Find all the prime factors of m.
Step 2: Find all the prime factors of n.
Step 3: Find the common factors in both the above expansions.
Step 4: Multiply the common factors and return it as GCD.
*/

#include<stdio.h>

int GCD(int m, int n){
	int min=m>n?n:m;
	int gcd=1;
	int fact;

	for(fact=2; fact<=min; fact++)
	{
		while(m%fact==0 && n%fact==0)
		{
			gcd*=fact;
			m/=fact;
			n/=fact;
		}

		if(m==0 || n==0)
			break;
	}	
	return gcd;
}

int main()
{
	int m, n;
	printf("Enter the values of m and n:\n");
	scanf("%d %d", &m, &n);

	printf("The GCD of %d and %d is %d\n", m, n, GCD(m, n));
	return 0;
}

