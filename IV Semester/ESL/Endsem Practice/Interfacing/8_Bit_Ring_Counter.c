#include<LPC17xx.h>

unsigned long counter=0x00000010;
unsigned int i, m=0;

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
		LPC_GPIO0->FIOPIN=counter;
		delay();
		counter<<1;

		if(counter==0x00001000)
			counter=0x00000010;
	}

	return 0;
}