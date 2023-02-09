#include<stdio.h>

int opcount=0;

int GCD(int n1, int n2){
	int min=n1>n2?n2:n1;

	while(min>0)
	{
		opcount++;
		if(n1%min==0)
		{
			if(n2%min==0)
				return min;
			else
				min--;
		}
		else
			min--;
	}
	return 1;
}

int main()
{
	int n1, n2;

	printf("Enter the first number:\n");
	scanf("%d",&n1);

	printf("Enter the second number:\n");
	scanf("%d",&n2);

	printf("The GCD of %d and %d is %d\n", n1, n2, GCD(n1, n2));
	printf("The opcount is %d\n", opcount);
	return 0;
}