#include<LPC17xx.h>
#include "LCD_Functions.c"

unsigned char scan_code[]={0x11, 0x21, 0x41, 0x81, 0x12, 0x22, 0x42, 0x82, 0x14, 0x24, 0x44, 0x84, 0x18, 0x28, 0x48, 0x88};
unsigned char ascii_code[]={'1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
unsigned char fin_ans[3];
unsigned int count=0, row, flag, i;
unsigned int a, b, ans, idx=1;
unsigned char op;
unsigned long int var, temp;

void Scan(void)
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

	LPC_GPIO2->FIODIR |= (0xF<<10);
	LPC_GPIO1->FIODIR &= ~(0xF<<23);

	lcd_init();
	lcd_com(0x80, 0);
	delay_lcd(800);

	while(count<3)
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

				LPC_GPIO2->FIOCLR=(0xF<<10);
				LPC_GPIO2->FIOSET=var;

				flag=0;
				Scan();
				if(flag==1)
				{
					count++;
					break;
				}
			}
			if(flag==1)
				break;
		}

		for(i=0; i<16; i++)
		{
			if(key==scan_code[i])
			{
				key=ascii_code[i];
				lcd_puts(&key);

				if(count==0)
					a=key-48;
				else if(count=1)
					op=key;
				else
					b=key-48;
				break;
			}
		}
	}

	lcd_com(0xC0, 0);
	delay_lcd(800);

	switch(op)
	{
		case '+': ans=a+b; break;
		case '-': ans=a-b; break;
	}

	while(ans!=0)
	{
		fin_ans[idx--]=(ans%10)+48;
		ans=ans/10;
	}

	lcd_puts(&fin_ans[o]);

	return 0;
}