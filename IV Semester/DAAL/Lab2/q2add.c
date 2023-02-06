#include<stdio.h>

void tower(int n, char from, char to, char aux)
{
	if(n==1)
	{
		printf("Move disk 1 from tower %c to %c. \n", from, to);
		return;
	}
	tower(n-1, from, aux, to);
	printf("Move disk %d from tower %c to %c. \n", n, from, to);
	tower(n-1, aux, to, from);
}

int main()
{
	char from='A', to='B', aux='C';
	int n;

	printf("Enter the number of disks: \n");
	scanf("%d", &n);

	tower(n, from, to, aux);
}