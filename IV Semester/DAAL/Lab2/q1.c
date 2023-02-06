#include<stdio.h>
#include<stdlib.h>

int GCD(int n1, int n2){
	int min=n1>n2?n2:n1;

	while(min>0){
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

int main(){
	int n1, n2;

	printf("Enter first integer:\t");
	scanf("%d", &n1);

	printf("Enter second integer:\t");
	scanf("%d", &n2);

	printf("The GCD of %d and %d is %d\n", n1, n2, GCD(n1, n2));
	return 0;
}