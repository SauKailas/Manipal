#include<LPC17xx.h>

unsigned int seg_select[]={0<<23, 1<<23, 2<<23, 3<<23};
unsigned int dig1=0x00, dig2=0x00, dig3=0x00, dig4=0x00, seg_count=0x00, temp1=0x00;
unsigned char array_dec[]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

unsigned int i, m=0;

void delay(void)
{
	for(i=0; i<10000; i++)
		m++;
}

void display(void)
{
	LPC_GPIO1->FIOPIN=seg_select[seg_count];

	if(seg_count==0x00)
		temp1=dig1;
	else if(seg_count==0x01)
		temp1=dig2;
	else if(seg_count==0x02)
		temp1=dig3;
	else
		temp1=dig4;

	LPC_GPIO0->FIOPIN=array_dec[temp1]<<4;
	delay();
}

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();

	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR |= (0xFF<<4);
	LPC_GPIO1->FIODIR |= (0xF<<23); //P1.23 to P1.26

	while(1)
	{
		delay();
		display();
		seg_count=seg_count+1;

		if(seg_count==0x04)
		{
			seg_count=0x00;
			dig1=dig1+1;

			if(dig1==0x0A)
			{
				dig1=0x00;
				dig2=dig2+1;

				if(dig2==0x0A)
				{
					dig2=0x00;
					dig3=dig3+1;

					if(dig3==0x0A)
					{
						dig3=0x00;
						dig4=dig4+1;

						if(dig4==0x0A)
							dig4=0x00;
					}
				}
			}
		}
	}
	return 0;
}