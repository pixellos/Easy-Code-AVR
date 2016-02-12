/*
 * sh1106.h
 *
 *  Created on: 2 lip 2015
 *      Author: Piter3132
 */

#ifndef SH1106_SH1106_H_
#define SH1106_SH1106_H_
#define swap(a, b) { int16_t t = a; a = b; b = t; }
#define lenght (SH1106_WIDTH * SH1106_HEIGHT / 8)
#define SH1106_WIDTH 128
#define SH1106_HEIGHT 64
/********************Konfiguracja Pinów********************/
#define USE_CS  1
#define USE_RST 0

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
#define CS			PIN4_bm
/********************Szybka zmiana stanów********************/
#define DC_LOW 		PORTxCLR = DC
#define DC_HIGH		PORTxSET = DC

#define RESET_LOW 	PORTxCLR = RESET
#define RESET_HIGH	PORTxSET = RESET

#define CS_LOW 		PORTxCLR = CS
#define CS_HIGH		PORTxSET = CS
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
///extern uint8_t bufor[lenght];
extern const uint8_t font5x7[];
extern int cursor_x, cursor_y;
/********************Deklaracje funkcjii********************/
/**********Sprzêt****************************************/

void SPI_Init (void);
void SPI_Send (uint8_t data);
void sh1106_cmd (uint8_t cmd);
void sh1106_data (uint8_t data);
void sh1106_init (uint8_t refresh, uint8_t contrast);
void sh1106_display (void);
// **********Grafika*********************************/
void bufor_clear (void);
void draw_bufor_pixel (int16_t x, int16_t y, uint8_t blackwhite);
void draw_bufor_line (int x0, int y0, int x1, int y1, uint8_t blackwhite);
void draw_bufor_vline (int8_t x, int8_t y1, int8_t y2, uint8_t blackwhite);
void draw_bufor_hline (int8_t x1, int8_t x2, int8_t y, uint8_t blackwhite);
void draw_bufor_rect (int x, int y, int width, int height, uint8_t blackwhite);
void draw_bufor_bitmap (int16_t x, int16_t y, const uint8_t *bitmap, uint8_t width, uint8_t height, uint8_t blackwhite);
void draw_bufor_char (int x, int y, char c, uint8_t blackwhite, uint8_t background, uint8_t size);
void draw_bufor_string (int x, int y, char * string, uint8_t blackwhite, uint8_t background, uint8_t size_text);
void draw_bufor_int (int x, int y, int data, uint8_t blackwhite, uint8_t background, uint8_t size_txt);
void draw_bufor_long (int x, int y, long int data, uint8_t blackwhite, uint8_t background, uint8_t size_txt);
#endif /* SH1106_SH1106_H_ */
