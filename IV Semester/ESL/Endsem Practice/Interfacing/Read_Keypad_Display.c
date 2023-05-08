#include<LPC17xx.h>
#include "LCD_Functions.c"

unsigned char Msg1[]={"KEY PRESSED: "};
unsigned char scan_code[16]={0x11, 0x21, 0x41, 0x81, 0x12, 0x22, 0x42, 0x82, 0x14, 0x24, 0x44, 0x84, 0x18, 0x28, 0x48, 0x88};
unsigned char ascii_code[16]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
unsigned int row, flag, i;
unsigned long int var;

void scan(void)
{
	temp=LPC_GPIO1->FIOPIN & (0xF<<23);
	if(!temp)
	{
		flag=1;
		temp>>=19;
		var>>=10;
		key=temp|var;
	}
}

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();

	LPC_GPIO2->FIODIR |= (0xF<<10); //Make P2.10 to P2.13 as output
	LPC_GPIO1->FIODIR &= ~(0xF<<23); //Make P1.23 to P1.26 as input

	lcd_init();
	lcd_comdata(0x80, 0);
	delay_lcd(800);
	lcd_puts(&Msg1[0]);

	while(1)
	{
		while(1)
		{
			for(row=1; row<5; row++)
			{
				if(row==1)
					var=0x00000400;
				else if(row==2)
					var=0x00000800;
				else if(row==3)
					var=0x00001000;
				else
					var=0x00002000;

				LPC_GPIO2->FIOCLR=(0xF<<10);	//Clear the port
				LPC_GPIO2->FIOSET=var;			//Enable the row
				flag=0;
				Scan();
				if(flag==1)
					break;
			}
			if(flag==1)
				break;
		}

		for(i=0; i<16; i++)
		{
			if(key==scan_code[i])
			{
				key=ascii_code[i];
				break;
			}
		}

		lcd_comdata(0xC0, 0);
		delay_lcd(800);
		lcd_puts(&key);
	}
	return 0;
}