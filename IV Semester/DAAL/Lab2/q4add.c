#include<stdio.h>
#include<stdlib.h>

int Factorial(int n){
	if(n==1)
		return 1;
	return n*Factorial(n-1);
}

int isStrong(int n){
	int strong=0;
	int dig, m=n;

	while(m>0){
		dig=m%10;
		strong+=Factorial(dig);
		m/=10;
	}

	if(strong==n)
		return 1;
	return 0;
}

int main()
{
	int len, arr[20];

	printf("Enter the array length:\t");
	scanf("%d", &len);

	for(int i=0; i<len; i++)
	{
		printf("Enter element:\t");
		scanf("%d", &arr[i]);
	}

	for(int i=0; i<len; i++)
	{
		if(isStrong(arr[i]))
		{
			for(int j=i; j<len; j++)
				arr[j]=arr[j+1];
			i--;
			len--;
		}
	}

	printf("The modified array is:\n");
	for(int i=0; i<len; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}