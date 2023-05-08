#include<LPC17xx.h>

unsigned int i, m=0, k, j;
unsigned long int var;

void delay(void)
{
	for(i=0; i<30000; i++)
		m++;
}

void clock_wise(void)
{
	var=0x00000010;

	for(j=0; j<=3; j++)
	{
		LPC_GPIO0->FIOPIN=var;
		var=var<<1;
		for(i=0; i<3000; i++);
	}
}

void anti_clock_wise(void)
{
	var=0x00000100;

	for(j=0; j<=3; j++)
	{
		LPC_GPIO0->FIOPIN=var;
		var=var>>1;
		for(i=0; i<3000; i++);
	}
}

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();

	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR |= (0xF<<4);

	while(1)
	{
		for(k=0; k<50; k++)
			clock_wise();
		delay();
		for(k=0; k<50; k++)
			anti_clock_wise();
		delay();
	}
	return 0;
}