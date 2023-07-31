#include <lpc17xx.h>

void lcd_init(void);
void write_cmd(void);
void delay_lcd(unsigned int);
void lcd_com(int);						   
void write_data(void);
void lcd_data(void);
void clear_ports(void);
void lcd_puts(unsigned char *);

unsigned char Msg3[11] = {"MIT"};
unsigned char Msg4[20] = {"Dept. of CSE:"};
unsigned long int temp1=0, temp2=0 ;

int main(void)
{
    /* Setting the directions as output */
    LPC_GPIO0->FIODIR |= 0x0F<<23 | 1<<27 | 1<<28;	
    clear_ports();
	delay_lcd(3200);
	
	lcd_init();
      
	lcd_com(0x80);	//First line first char
	delay_lcd(800);
	lcd_puts(&Msg3[0]);
     
	lcd_com(0xC0);	// Second line first char
	delay_lcd(800);
	lcd_puts(&Msg4[0]);
}
//lcd initialization
	void lcd_init()
	{
		//4 bit mode
		lcd_com(0x33);	   
		delay_lcd(800); 

		lcd_com(0x32);  
		delay_lcd(800);
			 
		lcd_com(0x28);		//function set
		delay_lcd(800);
		
		lcd_com(0x0c);		//display on cursor off	
		delay_lcd(800);
		
		lcd_com(0x06);		//entry mode set increment cursor right
		delay_lcd(800);
	 
		lcd_com(0x01);		//display clear
		delay_lcd(10000);
		
		return;
	 }

 void clear_ports(void)
 {
    /* Clearing the lines at power on */
	LPC_GPIO0->FIOCLR = 0x0F<<23; //Clearing data lines
	LPC_GPIO0->FIOCLR = 1<<27;  //Clearing RS line
	LPC_GPIO0->FIOCLR = 1<<28; //Clearing Enable line
        
                 return;
 }
 void delay_lcd(unsigned int r1)
 {
  	unsigned int r;
  	for(r=0;r<r1;r++);
    return;
 }
 void lcd_com(int temp1)
 {
	temp2 = temp1 & 0xf0;          // get MS nibble
	temp2 = temp2 << 19;           //data lines from 23 to 26
	write_cmd();
	delay_lcd(30000);
	temp2 = temp1 & 0x0f;         //get LS nibble
	temp2 = temp2 << 23; 
	write_cmd();
	delay_lcd(30000);
    return;
 }

 // command nibble o/p routine
 void write_cmd(void)                 //write command reg
 { 	 
	clear_ports();
	LPC_GPIO0->FIOPIN = temp2;    // Assign the value to the data lines    
    LPC_GPIO0->FIOCLR = 1<<27;  // clear bit RS
	LPC_GPIO0->FIOSET = 1<<28;  // EN=1
	delay_lcd(25);
	LPC_GPIO0->FIOCLR  = 1<<28;	// EN =0
    return;
    
 }

 void lcd_puts(unsigned char *buf1)
 {
    unsigned int i=0;

    while(buf1[i]!='\0')
    {
        temp1 = buf1[i];
     	lcd_data();
		delay_lcd(800);
		i++;
        if(i==16)
		{
           	lcd_com(0xc0);
			delay_lcd(800);
		}
         
    }
    return;
 }
 // data o/p routine which also outputs high nibble first  and lower nibble next
 void lcd_data(void)
 {             
    temp2 = temp1 & 0xf0;
    temp2 = temp2 << 19;
    write_data();
    delay_lcd(30000);
    temp2= temp1 & 0x0f;	
    temp2= temp2 << 23;
    write_data();
    delay_lcd(30000);	
    return;
 } 

 // data nibble o/p routine
 void write_data(void)
 {  	  
	clear_ports();
	LPC_GPIO0->FIOPIN = temp2;	// Assign the value to the data lines  
    LPC_GPIO0->FIOSET = 1<<27;	// set bit  RS
	LPC_GPIO0->FIOSET = 1<<28;   	// EN=1
	delay_lcd(25);
	LPC_GPIO0->FIOCLR = 1<<28;	// EN =0
    return;
 }
