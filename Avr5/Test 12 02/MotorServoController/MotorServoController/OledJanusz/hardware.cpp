/*
 * hardware.c
 *
 *  Created on: 2 lip 2015
 *      Author: Piter3132
 */

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
#include "SPL/Avr5Lib.hpp"
#include "sh1106.h"

void SPI_Init (void)
{
	Mosi.FastAsOutput();
	Sck.FastAsOutput;
	Dc.FastAsOutput();
	Reset.FastAsOutput();
	Cs.FastAsOutput();
	//DIRxSET = ( MOSI ) | ( SCK ) | ( DC );	//ustawienie pinów do komunikacji
	//#if USE_RST == 1
	//DIRxSET = RESET;
	Reset.Set();
	_delay_ms(50);
	Reset.Clear();
	_delay_ms(50);
	Reset.Set();
	//#endif
// 
// #if USE_CS == 1
// DIRxSET = CS;

	Cs.Set();
	_delay_ms(25);
	Cs.Clear();
	_delay_ms(25);
	Cs.Set();
/*	#endif*/
	SPI::AsMaster();
	SPI::SpiMode3();
	SPI::SetDoubleSpeed();
	SPI::SPIEnable();

	//SPIE.CTRL = SPI_ENABLE_bm | SPI_MASTER_bm | SPI_MODE_3_gc | SPI_CLK2X_bm;// | SPI_PRESCALER_DIV4_gc;
//	SPIE.INTCTRL = SPI_INTLVL_LO_gc;
}


/********************Wysy³anie przez SPI********************/

void SPI_Send (uint8_t data)
{
	SPI::SetData(data);
	while(!CheckOperationCompleteFlag);  //czekanie na zakoñczenie wysy³ania bajtu
}


/********************Wysy³anie do OLEDa********************/

// komendy
void sh1106_cmd (uint8_t cmd)
{
	//#if USE_CS == 1
	Cs.Set();
	//#endif

	Dc.Clear();

	Cs.Clear();

	SPI_Send (cmd);


	Cs.Set();

}

// Dane
void sh1106_data (uint8_t data)
{
	Cs.Set();
	Dc.Set();

	Cs.Clear();

	SPI_Send (data);

	Cs.Set();
}


/********************Inicjalizacja OLEDa********************/

void sh1106_init (uint8_t refresh, uint8_t contrast)
{
	SPI_Init();

	Cs.Clear();
	Dc.Clear();

	SPI_Send (SH1106_DISPLAYOFF);
	SPI_Send (SH1106_SETMULTIPLEX);
	SPI_Send (0x3F);
	SPI_Send (SH1106_SETSTARTLINE);        /*set display start line*/
	SPI_Send (SH1106_PAGEADDR);   		 	/*set page address*/
	SPI_Send (SH1106_SETLOWCOLUMN|0x02);	/*set lower column address*/
	SPI_Send (SH1106_SETHIGHCOLUMN);    	/*set higher column address*/
	SPI_Send (SH1106_SEGREMAP|0x01); 		/*set segment remap*/
	SPI_Send (SH1106_NORMALDISPLAY);    	/*normal / reverse*/
	SPI_Send (SH1106_CHARGEPUMP);			/*set charge pump enable*/
	SPI_Send (SH1106_MEMORYMODE);
	SPI_Send (0x00);
	SPI_Send (SH1106_EXTERNALVCC);			/*external VCC   */
	SPI_Send (0x31);  						/*0X30---0X33  7,4V-8V-8,4V-9V */
	_delay_ms(10);
	SPI_Send (SH1106_COMSCANDEC);    		/*Com scan direction*/
	SPI_Send (SH1106_SETDISPLAYOFFSET);    /*set display offset*/
	SPI_Send (0x00);   						/*   0x20  /   0x00 */
	SPI_Send (SH1106_SETDISPLAYCLOCKDIV);  /*set osc division*/
	SPI_Send (refresh);
	SPI_Send (SH1106_SETPRECHARGE);    	/*set pre-charge period*/
	SPI_Send (0x1f);    					/*0x22  /  0x1f*/
	SPI_Send (SH1106_SETCOMPINS);    		/*set COM pins*/
	SPI_Send (0x12);
	SPI_Send (SH1106_SETVCOMDETECT);    	/*set vcomh*/
	SPI_Send (0x40);
	SPI_Send (SH1106_SETCONTRAST);
	SPI_Send (contrast);

	SPI_Send (SH1106_DISPLAYALLON_RESUME);
	SPI_Send (SH1106_NORMALDISPLAY);
	// turn on oled panel
	SPI_Send (SH1106_DISPLAYON);

	Cs.Set();
	// wait 100ms
//	_delay_ms(50);

//	bufor_clear();
	//sh1106_display();
}


/********************Przesy³anie bufora do pamieci OLEDa********************/
/*
void sh1106_display (void)
{
	#if USE_CS == 1
		CS_LOW;
		#endif

	DC_LOW;
	SPI_Send (SH1106_SETLOWCOLUMN);


	SPI_Send (0xB0);
//	SPI_Send (SH1106_SETLOWCOLUMN);
	SPI_Send (SH1106_SETHIGHCOLUMN);
	DC_HIGH;
	for( uint8_t i=0; i<128; i++ ) { SPI_Send(bufor[i]); }

	DC_LOW;
	SPI_Send (0xB1);
//	SPI_Send (SH1106_SETLOWCOLUMN);
	SPI_Send (SH1106_SETHIGHCOLUMN);
	DC_HIGH;
	for( uint8_t i=0; i<128; i++ ) { SPI_Send(bufor[i+128]); }

	DC_LOW;
	SPI_Send (0xB2);
//	SPI_Send (SH1106_SETLOWCOLUMN);
	SPI_Send (SH1106_SETHIGHCOLUMN);
	DC_HIGH;
	for( uint8_t i=0; i<128; i++ ) { SPI_Send(bufor[i+256]); }

	DC_LOW;
	SPI_Send (0xB3);
//	SPI_Send (SH1106_SETLOWCOLUMN);
	SPI_Send (SH1106_SETHIGHCOLUMN);
	DC_HIGH;
	for( uint8_t i=0; i<128; i++ ) { SPI_Send(bufor[i+384]); }

	DC_LOW;
	SPI_Send (0xB4);
//	SPI_Send (SH1106_SETLOWCOLUMN);
	SPI_Send (SH1106_SETHIGHCOLUMN);
	DC_HIGH;
	for( uint8_t i=0; i<128; i++ ) { SPI_Send(bufor[i+512]); }

	DC_LOW;
	SPI_Send (0xB5);
//	SPI_Send (SH1106_SETLOWCOLUMN);
	SPI_Send (SH1106_SETHIGHCOLUMN);
	DC_HIGH;
	for( uint8_t i=0; i<128; i++ ) { SPI_Send(bufor[i+640]); }

	DC_LOW;
	SPI_Send (0xB6);
//	SPI_Send (SH1106_SETLOWCOLUMN);
	SPI_Send (SH1106_SETHIGHCOLUMN);
	DC_HIGH;
	for( uint8_t i=0; i<128; i++ ) { SPI_Send(bufor[i+768]); }

	DC_LOW;
	SPI_Send (0xB7);
//	SPI_Send (SH1106_SETLOWCOLUMN);
	SPI_Send (SH1106_SETHIGHCOLUMN);
	DC_HIGH;
	for( uint8_t i=0; i<128; i++ ) { SPI_Send(bufor[i+896]); }

	#if USE_CS == 1
		CS_HIGH;
		#endif
}


*/







