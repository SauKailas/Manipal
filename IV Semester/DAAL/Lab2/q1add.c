#include<stdio.h>
#include<stdlib.h>

int main(){
	int n, i;

	printf("Enter a positive integer:\t");
	scanf("%d", &n);

	for(i=1; i<=n/2; i++){
		if(i*i<=n && (i+1)*(i+1)>n)
			break;
	}
	
	printf("The floor of the square root of %d is %d\n", n, i);
	return 0;
}