/*
 * sh1106.h
 *
 *  Created on: 2 lip 2015
 *      Author: Piter3132
 */

#ifndef SH1106_SH1106_H_
#define SH1106_SH1106_H_

static inline void swap(char* a, char* b){
	char temp = *a;
	*a = *b;
	*b = temp;
}


#define lenght (SH1106_WIDTH * SH1106_HEIGHT / 8)
#define SH1106_WIDTH 128
#define SH1106_HEIGHT 64


/********************Konfiguracja Pinów********************/


#define USE_CS  1
#define USE_RST 0/*

#define PORTx  		PORTE.OUT
#define PORTxCLR 	PORTE.OUTCLR
#define PORTxSET 	PORTE.OUTSET
#define DIRx  		PORTE.DIR
#define DIRxCLR 	PORTE.DIRCLR
#define DIRxSET 	PORTE.DIRSET

#define SCK_PORT 	PORTx
#define SCK			PIN7_bm

#define MOSI_PORT	PORTx
#define MOSI		PIN5_bm

#define RESET_PORT	PORTx
#define RESET		PIN2_bm

#define DC_PORT		PORTx
#define DC			PIN3_bm

#define CS_PORT		PORTx
#define CS			PIN4_bm*/


/********************Szybka zmiana stanów********************/
/*

#define DC_LOW 		PORTxCLR = DC
#define DC_HIGH		PORTxSET = DC

#define RESET_LOW 	PORTxCLR = RESET
#define RESET_HIGH	PORTxSET = RESET

#define CS_LOW 		PORTxCLR = CS
#define CS_HIGH		PORTxSET = CS
*/

/********************Odœwierzanie OLEDa********************/


#define REFRESH_MIN 0x80
#define REFRESH_MID 0xB0
#define REFRESH_MAX 0xF0


/********************Opcje sterowania********************/


#define SH1106_SETCONTRAST 0x81
#define SH1106_DISPLAYALLON_RESUME 0xA4
#define SH1106_DISPLAYALLON 0xA5
#define SH1106_NORMALDISPLAY 0xA6
#define SH1106_INVERTDISPLAY 0xA7
#define SH1106_DISPLAYOFF 0xAE
#define SH1106_DISPLAYON 0xAF

#define SH1106_SETDISPLAYOFFSET 0xD3
#define SH1106_SETCOMPINS 0xDA

#define SH1106_SETVCOMDETECT 0xDB

#define SH1106_SETDISPLAYCLOCKDIV 0xD5
#define SH1106_SETPRECHARGE 0xD9

#define SH1106_SETMULTIPLEX 0xA8

#define SH1106_SETLOWCOLUMN 0x02    //ssd1306 ma 0x00   //w sh1106 przesuwamy o 0x02 czyli setlowcolumn | 0x02
#define SH1106_SETHIGHCOLUMN 0x10

#define SH1106_SETSTARTLINE 0x40

#define SH1106_MEMORYMODE 0x20
#define SH1106_COLUMNADDR 0x21
#define SH1106_PAGEADDR   0xB0    //ssd1306 ma 0x22

#define SH1106_COMSCANINC 0xC0
#define SH1106_COMSCANDEC 0xC8

#define SH1106_SEGREMAP 0xA0

#define SH1106_CHARGEPUMP 0xAD    // ssd1306 ma 8D

#define SH1106_EXTERNALVCC 0x8B    // ssd1306 ma 0x1
#define SH1106_SWITCHCAPVCC 0x2

// Scrolling #defines
#define SH1106_ACTIVATE_SCROLL 0x2F
#define SH1106_DEACTIVATE_SCROLL 0x2E
#define SH1106_SET_VERTICAL_SCROLL_AREA 0xA3
#define SH1106_RIGHT_HORIZONTAL_SCROLL 0x26
#define SH1106_LEFT_HORIZONTAL_SCROLL 0x27
#define SH1106_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29
#define SH1106_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A


/********************Deklaracje zmiennych********************/



/********************Deklaracje funkcjii********************/


// **********Sprzêt











#endif /* SH1106_SH1106_H_ */
