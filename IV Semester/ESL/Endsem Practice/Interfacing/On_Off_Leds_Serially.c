#include<LPC17xx.h>

unsigned long LED;
unsigned int i, j, m=0;

void delay(void)
{
	for(j=0; j<10000; j++)
		m++;
}

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();

	LPC_PINCON->PINSEL0 &= 0xFF00000FF;
	LPC_GPIO0->FIOPIN |= (0xFF<<4);

	while(1)
	{
		LED=0x00000010;
		for(i=0; i<9; i++)
		{
			LPC_GPIO0->FIOSET=LED;
			delay();
			LED<<=1;
		}

		LED=0x00000010;
		for(i=0; i<9; i++)
		{
			LPC_GPIO0->FIOCLR=LED;
			delay();
			LED<<=1;
		}
	}

	return 0;
}