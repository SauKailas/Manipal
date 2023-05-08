#include<LPC17xx.h>

unsigned int i, m=0, c;

void delay(void)
{
	for(i=0; i<10000; i++)
		m++;
}

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();

	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR |= (0xFF<<4);

	while(1)
	{
		for(c=0; c<256; c++)
		{
			LPC_GPIO0->FIOPIN=c;
			delay();
		}
	}
	return 0;
}