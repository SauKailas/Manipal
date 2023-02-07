#include<stdio.h>

int GCD(int n1, int n2){

	int min=(n1>n2)?n2:n1;
	int gcd=1;

	for(int fact=2; fact<=min; fact++)
	{
		while((n1%fact==0) && (n2%fact==0))
		{
			gcd*=fact;
			n1/=fact;
			n2/=fact;

			if(n1==1 || n2==1)
				return gcd;
		}
	}
	return gcd;
}


int main()
{
	int n1, n2;

	printf("Enter first number:\t");
	scanf("%d", &n1);
	printf("Enter second number:\t");
	scanf("%d", &n2);

	printf("The GCD of %d and %d is %d\n", n1, n2, GCD(n1, n2));
	return 0;
}