/*
 *  Created on: Feb 19, 2014
 *      Author: Nelson Antonio PÃ©rez Cervantes
 */
#include "derivative.h"
#include "cfgps2.h"
#include "lcd.h"
#include "Keyboard.h"

void teclado_use(void)
{
	if (data_ready)
	{
		teclado = data;
		data_ready = 0;
	}
	if ((teclado != 0xF0) && (teclado) && (teclado != 0xE0))
	{
			switch (teclado)
			{
			case 0x15:
				alternative_mayus('Q','q');
				break;
			case 0x1D:
				alternative_mayus('W','w');
				break;
			case 0x24:
				alternative_mayus('E','e');
				break;
			case 0x2D:
				alternative_mayus('R','r');
				break;
			case 0x2C:
				alternative_mayus('T','t');
				break;
			case 0x35:
				alternative_mayus('Y','y');
				break;
			case 0x3C:
				alternative_mayus('U','u');
				break;
			case 0x43:
				alternative_mayus('I','i');
				break;	
			case 0x44:
				alternative_mayus('O','o');
				break;
			case 0x4D:
				alternative_mayus('P','p');
				break;
			case 0x1C:
				alternative_mayus('A','a');
				break;
			case 0x1B:
				alternative_mayus('S','s');
				break;
			case 0x23:
				alternative_mayus('D','d');
				break;
			case 0x2B:
				alternative_mayus('F','f');
				break;
			case 0x34:
				alternative_mayus('G','g');
				break;
			case 0x33:
				alternative_mayus('H','h');
				break;
			case 0x3B:
				alternative_mayus('J','j');
				break;
			case 0x42:
				alternative_mayus('K','k');
				break;
			case 0x4B:
				alternative_mayus('L','l');
				break;
			case 0x1A:
				alternative_mayus('Z','z');
				break;
			case 0x22:
				alternative_mayus('X','x');
				break;
			case 0x21:
				alternative_mayus('C','c');
				break;
			case 0x2A:
				alternative_mayus('V','v');
				break;
			case 0x32:
				alternative_mayus('B','b');
				break;
			case 0x31:
				alternative_mayus('N','n');
				break;
			case 0x3A:
				alternative_mayus('M','m');
				break;
			case 0x58:
				bloq_mayus();
				break;
			case 0x12:
				shift_use();
				break;
			case 0x59:
				shift_use();
				break;
			case 0x29:
				writeLCD(' ');
				break;
			case 0x16:
				alternative_key('1','!');
				break;
			case 0x1E:
				alternative_key('2','"');
				break;
			case 0x26:
				alternative_key('3','#');
				break;
			case 0x25:
				alternative_key('4','$');
				break;
			case 0x2E:
				alternative_key('5','%');
				break;
			case 0x36:
				alternative_key('6','&');
				break;
			case 0x3D:
				alternative_key('7','/');
				break;
			case 0x3E:
				alternative_key('8','(');
				break;
			case 0x46:
				alternative_key('9',')');
				break;
			case 0x45:
				alternative_key('0','=');
				break;
			case 0x66:
				deleteLCD();
				break;
			case 0x4E:
				alternative_key(0x27,'?');
				break;
			case 0x55:
				alternative_key('¿','¡');
				break;
			case 0x5B:
				alternative_key('+','*');
				break;
			case 0x52:
				alternative_key('{','[');
				break;
			case 0x5D:
				alternative_key('}',']');
				break;
			case 0x41:
				alternative_key(',',';');
				break;
			case 0x49:
				alternative_key('.',':');
				break;
			case 0x4A:
				alternative_key('-','_');
				break;
			case 0x61:
				alternative_key('<','>');
				break;
			case 0x0E:
				alternative_key('|','°');
				break;
			case 0x74:
				despla_der();
				break;
			case 0x75:
				despla_up();
				break;
			case 0x6B:
				despla_izq();
				break;
			case 0x72:
				despla_down();
				break;
			case 0x05:
				F_keyboad(0);
				break;
			case 0x06:
				F_keyboad(1);
				break;
			case 0x04:
				F_keyboad(2);
				break;
			case 0x0C:
				F_keyboad(3);
				break;
			case 0x03:
				F_keyboad(4);
				break;
			case 0x0B:
				F_keyboad(5);
				break;
			case 0x83:
				F_keyboad(6);
				break;
			case 0x0A:
				F_keyboad(7);
				break;
			case 0x5A:
				enter();
				break;
			case 0x76:
				clear_page();
				break;
			default:
				uart_use();
				break;
			}
	teclado = 0;
	}
}
void LCD_use(void)
{
	switch (page)
	{
		case 0:
			sendCode(nIns,0x80);
			for (place=0;place < 16;place++)
			{
				sendCode(nData,LCD[place]);
			}
			sendCode(nIns,0xC0);
			for (place=16;place < 32;place++)
			{
				sendCode(nData,LCD[place]);
			}
			if (pos < 16)
			{
				sendCode(nIns,pos+0x80);
			}
			else if ((pos >= 16)&&(pos < 32))
			{
				sendCode(nIns,pos+0xB0);
			}
			break;
		case 1:
			sendCode(nIns,0x80);
			for (place=32;place < 48;place++)
			{
				sendCode(nData,LCD[place]);
			}
			sendCode(nIns,0xC0);
			for (place=48;place < 64;place++)
			{
				sendCode(nData,LCD[place]);
			}
			if (pos < 48)
			{
				sendCode(nIns,pos-32+0x80);
			}
			else if ((pos >= 48)&&(pos < 64))
			{
				sendCode(nIns,pos-32+0xB0);
			}
			break;
		case 2:
			sendCode(nIns,0x80);
			for (place=64;place < 80;place++)
			{
				sendCode(nData,LCD[place]);
			}
			sendCode(nIns,0xC0);
			for (place=80;place < 96;place++)
			{
				sendCode(nData,LCD[place]);
			}
			if (pos < 80)
			{
				sendCode(nIns,pos-64+0x80);
			}
			else if ((pos >= 80)&&(pos < 96))
			{
				sendCode(nIns,pos-64+0xB0);
			}
			break;
		case 3:
			sendCode(nIns,0x80);
			for (place=96;place < 112;place++)
			{
				sendCode(nData,LCD[place]);
			}
			sendCode(nIns,0xC0);
			for (place=112;place < 128 ;place++)
			{
				sendCode(nData,LCD[place]);
			}
			if (pos < 112)
			{
				sendCode(nIns,pos-96+0x80);
			}
			else if ((pos >= 112)&&(pos < 128))
			{
				sendCode(nIns,pos-96+0xB0);
			}
			break;
		case 4:
			sendCode(nIns,0x80);
			for (place=128;place < 144;place++)
			{
				sendCode(nData,LCD[place]);
			}
			sendCode(nIns,0xC0);
			for (place=144;place < 160 ;place++)
			{
				sendCode(nData,LCD[place]);
			}
			if (pos < 144)
			{
				sendCode(nIns,pos-128+0x80);
			}
			else if ((pos >= 144)&&(pos < 160))
			{
				sendCode(nIns,pos-128+0xB0);
			}
			break;
		case 5:
			sendCode(nIns,0x80);
			for (place=160;place < 176;place++)
			{
				sendCode(nData,LCD[place]);
			}
			sendCode(nIns,0xC0);
			for (place=176;place < 192;place++)
			{
				sendCode(nData,LCD[place]);
			}
			if (pos < 176)
			{
				sendCode(nIns,pos-160+0x80);
			}
			else if ((pos >= 176)&&(pos < 192))
			{
				sendCode(nIns,pos-160+0xB0);
			}
			break;
		case 6:
			sendCode(nIns,0x80);
			for (place=192;place < 208;place++)
			{
				sendCode(nData,LCD[place]);
			}
			sendCode(nIns,0xC0);
			for (place=208;place < 224;place++)
			{
				sendCode(nData,LCD[place]);
			}
			if (pos < 208)
			{
				sendCode(nIns,pos-192+0x80);
			}
			else if ((pos >= 208)&&(pos < 224))
			{
				sendCode(nIns,pos-192+0xB0);
			}
			break;
		case 7:
			sendCode(nIns,0x80);
			for (place=224;place < 240;place++)
			{
				sendCode(nData,LCD[place]);
			}
			sendCode(nIns,0xC0);
			for (place=240;place < 256;place++)
			{
				sendCode(nData,LCD[place]);
			}
			if (pos < 240)
			{
				sendCode(nIns,pos-224+0x80);
			}
			else if ((pos >= 240)&&(pos < 256))
			{
				sendCode(nIns,pos-224+0xB0);
			}
			break;
	}
}
void UARTsend(void)
{
	switch (page)
		{
			case 0:
				for (place=0;place < 16;place++)
				{
					UART0_D = LCD[place];
					while ((UART0_S1 & 0x40) == 0);
				}
				for (place=16;place < 32;place++)
				{
					UART0_D = LCD[place];
					while ((UART0_S1 & 0x40) == 0);
				}
				
				break;
			case 1:
				for (place=32;place < 48;place++)
				{
					UART0_D = LCD[place];
					while ((UART0_S1 & 0x40) == 0);
				}
				for (place=48;place < 64;place++)
				{
					UART0_D = LCD[place];
					while ((UART0_S1 & 0x40) == 0);
				}
				
				break;
			case 2:
				for (place=64;place < 80;place++)
				{
					UART0_D = LCD[place];
					while ((UART0_S1 & 0x40) == 0);
				}
				for (place=80;place < 96;place++)
				{
					UART0_D = LCD[place];
					while ((UART0_S1 & 0x40) == 0);
				}
				
				break;
			case 3:
				for (place=96;place < 112;place++)
				{
					UART0_D = LCD[place];
					while ((UART0_S1 & 0x40) == 0);
				}
				for (place=112;place < 128 ;place++)
				{
					UART0_D = LCD[place];
					while ((UART0_S1 & 0x40) == 0);
				}
				
				break;
			case 4:
				
				for (place=128;place < 144;place++)
				{
					UART0_D = LCD[place];
										while ((UART0_S1 & 0x40) == 0);
				}
				
				for (place=144;place < 160 ;place++)
				{
					UART0_D = LCD[place];
										while ((UART0_S1 & 0x40) == 0);
				}
				
				break;
			case 5:
				for (place=160;place < 176;place++)
				{
					UART0_D = LCD[place];
										while ((UART0_S1 & 0x40) == 0);
				}
				
				for (place=176;place < 192;place++)
				{
					UART0_D = LCD[place];
										while ((UART0_S1 & 0x40) == 0);
				}
				break;
			case 6:
				
				for (place=192;place < 208;place++)
				{
					UART0_D = LCD[place];
										while ((UART0_S1 & 0x40) == 0);
				}
				
				for (place=208;place < 224;place++)
				{
					UART0_D = LCD[place];
										while ((UART0_S1 & 0x40) == 0);
				}
				break;
			case 7:
				
				for (place=224;place < 240;place++)
				{
					UART0_D = LCD[place];
										while ((UART0_S1 & 0x40) == 0);
				}
				
				for (place=240;place < 256;place++)
				{
					UART0_D = LCD[place];
										while ((UART0_S1 & 0x40) == 0);
				}
				break;
		}
}
