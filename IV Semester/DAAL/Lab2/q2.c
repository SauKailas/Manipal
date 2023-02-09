#include<stdio.h>

int opcount=0;

int GCD(int n1, int n2){
	int min=n1>n2?n2:n1;
	int gcd=1, fact;

	for(fact=2; fact<=min; fact++)
	{
		opcount++;
		while(n1%fact==0 && n2%fact==0)
		{
			gcd*=fact;
			n1/=fact;
			n2/=fact;

			if(n1==1||n2==1)
				return gcd;
		}
	}
	return gcd;
}

int main()
{
	int n1, n2;

	printf("Enter the first number:\n");
	scanf("%d", &n1);

	printf("Enter the second number:\n");
	scanf("%d", &n2);

	printf("The GCD of %d and %d is %d\n", n1, n2, GCD(n1, n2));
	printf("The opcount is %d\n", opcount);
	return 0;
}