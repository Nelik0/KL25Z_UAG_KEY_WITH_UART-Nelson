/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "derivative.h" /* include peripheral declarations */
#include "lcd.h"
#include "cfgps2.h"
#include "Keyboard.h"
int main(void)
{
	cfgPortPS2();
	cfgPortsLCD();
	teclado = 0;
	memory = 0; 
	mayus = 0;
	pos = 0;
	shift = 0;
	page = 0;
	uart = 0;
	UARTinit();
	sendCode(nIns,0x0D);
	for(place=0;place <= 255;place++)
	{
		LCD[place]= ' ';
	}
	writting = 0;
	for(;;) 
	{	
		teclado_use();
		if (writting)
		{
			LCD_use();
			writting = 0;
		}
		if (uart)
		{
			UARTsend();
			uart = 0;
		}
		
	}
	
	return 0;
}
