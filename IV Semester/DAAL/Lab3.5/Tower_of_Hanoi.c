#include <stdio.h>
#include<stdlib.h>

int opcount=0;

void Tower_of_Hanoi(int n, char src, char aux, char dst){

	opcount++;
	if(n==1)
	{
		printf("Move disk 1 from peg %c to peg %c\n", src, dst);
		return;
	}

	Tower_of_Hanoi(n-1, src, dst, aux);
	printf("Move disk %d from peg %c to peg %c\n", n, src, dst);
	Tower_of_Hanoi(n-1, aux, src, dst);
}

int main()
{
	int n;

	printf("Enter the number of disks:\t");
	scanf("%d", &n);

	printf("The moves are:\n");
	Tower_of_Hanoi(n, 'A', 'B', 'C');

	printf("The opcount is %d\n", opcount);

	return 0;
}