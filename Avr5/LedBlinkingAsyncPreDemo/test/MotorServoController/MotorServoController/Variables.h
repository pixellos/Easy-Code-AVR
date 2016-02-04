#ifndef VARIABLES_H_
#define VARIABLES_H_
Task taskName;
Task keyboardTask;
Task Leds;

char TextOk[3] = "Ok";
uint8_t elapsedTime = 0;

volatile static int16_t ledCounter = 0;
volatile static bool BlinkFlag =false;
volatile uint16_t ButtonPressTime = 0;

PIN_D7 Button;
PIN_B2 GreenLed;
PIN_B0 RedLed	;	//Controled by -, if Cleared - it shine
PIN_B1 YellowLed;		//Controled by -, if Cleared - it shine
#endif /* VARIABLES_H_ */