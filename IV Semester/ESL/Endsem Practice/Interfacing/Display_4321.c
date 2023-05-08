#include<LPC17xx.h>

unsigned int i, m=0;
unsigned int dig_count=0;
unsigned int dig_value[]={4, 3, 2, 1};
unsigned int disp_select[]={0<<23, 1<<23, 2<<23, 3<<23};
unsigned char array_dec[]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void delay(void)
{
	for(i=0; i<10000; i++)
		m++;
}

void display(void)
{
	LPC_GPIO1->FIOPIN=disp_select[dig_count];
	LPC_GPIO0->FIOPIN=array_dec[dig_value[dig_count]]<<4;
}

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();

	LPC_GPIO0->FIODIR |= (0xFF<<4);
	LPC_GPIO1->FIODIR |= (0xF<<23);

	while(1)
	{
		delay();
		display();
		dig_count=dig_count+1;

		if(dig_count==4)
			dig_count=0;
	}

	return 0;
}