/*
Write a program to find GCD using consecutive integer checking method and analyze its time efficiency.

ALGORITHM:
Input: Two non-negative integers, not both zero, m and n.
Output: Greatest commom divisor of m and n.
Step 1: Assign minimum of m and n to t.
Step 2: Divide m by t. If remainder is 0 go to Step 3, else go to Step 4.
Step 3: Divide n by t. If remainder return t and STOP, else go to Step 4.
Step 4: Decrease t by one and go to Step 2.
*/

#include<stdio.h>

int GCD(int m, int n){
	int t=m>n?n:m;

	while(t>0)
	{
		if(m%t==0)
		{
			if(n%t==0)
				return t;
			else
				t--;
		}
		else
			t--;
	}
	return 1;i
}

int main()
{
	int m, n;
	printf("Enter the values of m and n:\n");
	scanf("%d %d", &m, &n);

	printf("The GCD of %d and %d is %d\n", m, n, GCD(m, n));
	return 0;
} 