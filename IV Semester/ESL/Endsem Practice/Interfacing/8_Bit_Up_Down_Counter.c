#include<LPC17xx.h>

unsigned int j, m=0, c;

void delay(void)
{
	for(j=0; j<10000; j++)
		m++;
}

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();

	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR |= (0xFF<<4);	//Set Pins 0.4 to 0.11 as Output
	LPC_GPIO1->FIODIR &= ~(0x1<<7); //Set Pin 1.7 as Input, for key

	while(1)
	{
		if(LPC_GPIO1->FIOPIN & (0x1<<7)) //Key is not pressed, so up-counter
		{
			while(1)
			{
				for(c=0; c<256; c++)
				{
					LPC_GPIO0->FIOPIN=c;
					delay();
				}
			}
		}
		else
		{
			while(1)
			{
				for(c=255; c>=0; c--)
				{
					LPC_GPIO0->FIOPIN=c;
					delay();
				}
			}
		}
	}

	return 0;
}