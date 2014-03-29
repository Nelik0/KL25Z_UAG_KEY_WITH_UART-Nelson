/*
 *  Created on: Feb 19, 2014
 *      Author: Nelson Antonio Pérez Cervantes
 */
#include "derivative.h"
#include "cfgps2.h"
#include "lcd.h"

void dec_mouse(void)
{
	if (data_trama_ready)
	{	
		sendCode(nIns, 0x80);
		sendCode(nData,'X');
		sendCode(nData,':');
		sig_x = (((trama_mouse[0] & 0x10)/0x10));
		sig_y = ((trama_mouse[0] & 0x20)/0x20);
		value_x =(trama_mouse[1]);
		value_y =(trama_mouse[2]);

		if(sig_x)
		{
			coord_x = ~trama_mouse[1];
			sendCode(nData,'-');
		}
		else
		{
			coord_x = trama_mouse[1];
			sendCode(nData,'+');
		}
		if(coord_x<0)
		{
			coord_x = coord_x*(0-1);
		}
		BCD(coord_x);
		sendCode(nData,cen+0x30);
		sendCode(nData,dec+0x30);
		sendCode(nData,uni+0x30);
		sendCode(nData,' ');
		sendCode(nData,'Y');
		sendCode(nData,':');
		if(sig_y)
		{
			coord_y = ~trama_mouse[2];
			sendCode(nData,'-');
		}
		else
		{
			sendCode(nData,'+');
			coord_y = trama_mouse[2];
		}
		
		if(coord_y<0)
		{
			coord_y = coord_y*(0-1);
		}
		BCD(coord_y);
		sendCode(nData,cen+0x30);
		sendCode(nData,dec+0x30);
		sendCode(nData,uni+0x30);
		trama_mouse[0] = 0;
		trama_mouse[1] = 0;
		trama_mouse[2] = 0;
		trama_mouse[3] = 0;
		data_trama_ready = 0;
	}
}
