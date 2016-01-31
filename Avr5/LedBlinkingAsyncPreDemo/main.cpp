#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "CppHelpers.h"
#include "Avr5Lib.cpp"
#include "Async.h"
#include "V2.h"

using namespace CodeEasyAvr; 

volatile static int16_t ledCounter = 0;
volatile static bool BlinkFlag =false;

volatile uint16_t ButtonPressTime = 0;
#define Button		Pin_D7
#define GreenLed	Pin_B4	//Controled by -, if Cleared - it shine
#define RedLed		Pin_B0	//Controled by -, if Cleared - it shine
#define YellowLed	Pin_B1	//Controled by -, if Cleared - it shine

void LedBlinkPerDelayVariableMs(){
	if (BlinkFlag)
	{
		if (ledCounter > 100)
		{
			ledCounter = 0;
			Pin_B1.Toggle();
		}
		++ledCounter;
	}
	else 
	{
		YellowLed.Set();
	}
	
}

void KeyboardHandler(){//Per 1 ms it's invoked
	if (Button.Check()) 
	{
		++ButtonPressTime;
	}
	else 
	{
		if (ButtonPressTime > 220)
		{
			BlinkFlag = !BlinkFlag;
		}else if (ButtonPressTime > 15)
		{
			GreenLed.Toggle();
		}
		ButtonPressTime = 0;
	}
}

void RegisterTasks(){
	Task taskName;
	taskName.currentMethod = &LedBlinkPerDelayVariableMs;
	taskManager.Register(taskName);

	Task keyboardTask;
	keyboardTask.currentMethod = &KeyboardHandler;
	taskManager.Register(keyboardTask);
}

void InitializeProgram(){
	Button.		AsInput();

	GreenLed.	FastAsOutput();
	RedLed.		FastAsOutput();
	YellowLed.	FastAsOutput();

	GreenLed.	FastSet();
	RedLed.		FastSet();
	YellowLed.	FastSet();

	RegisterTasks();
	Async::EnableAsync();
	sei();
}

int main(){
	InitializeProgram();
	while(1);//Important, if program get out of main SREG bit will be cleared!
}
