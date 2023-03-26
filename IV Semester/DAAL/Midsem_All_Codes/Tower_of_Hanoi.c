/*Implement the recursive solution for Tower of Hanoi.*/

#include<stdio.h>

void Tower_of_Hanoi(int n, char src, char aux, char dst){
	if(n==1)
	{
		printf("Move disk 1 from peg %c to %c\n", src, dst);
		return;
	}

	Tower_of_Hanoi(n-1, src, dst, aux);
	printf("Move disk %d from peg %c to %c\n", n, src, dst);
	Tower_of_Hanoi(n-1, aux, src, dst);
}

int main()
{
	int n;
	printf("Enter the number of disks: ");
	scanf("%d", &n);

	printf("\nThe Steps are:\n");
	Tower_of_Hanoi(n, 'A', 'B', 'C');

	return 0;
}