#ifndef VARIABLES_H_
#define VARIABLES_H_
#include "Sh1106Class.h"
#include "Sh1106Class.cpp"
Task taskName;
Task keyboardTask;
Task Leds;

typedef void(*Action)();

uint8_t elapsedTime = 0;
volatile static int16_t ledCounter = 0;
volatile static bool BlinkFlag = false;
volatile uint16_t ButtonPressTime = 0;
volatile uint16_t OtherButtonPressTime = 0;

PIN_D6 OtherButton;
PIN_D7 Button;
PIN_B7 SPISck;
PIN_B6 SPIMiso;
PIN_B5 SPIMosi;
PIN_A0 GreenLed;
PIN_A1 RedLed	;	//Controled by -, if Cleared - it shine
PIN_A2 YellowLed;		//Controled by -, if Cleared - it shine
PIN_A3 DataCommand;
PIN_A4 Reset;
PIN_A5 OledChipSelect;
PIN_B4 SPISS;

Sh1106 debugDisplay(DataCommand,Reset,SPIMosi,OledChipSelect,SPISck,SPIMiso,SPISS);
#endif /* VARIABLES_H_ */