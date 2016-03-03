#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include "CppHelpers.h"
#include "Helpers/Screen.h"
#include "SPL/Avr5Lib.hpp"
#include "SPL/Atmega16A_SPL.hpp"
#include "TaskManager/TaskManager.hpp"
#include "HD44780.h"
#include "Variables.h"
#include "HD44780.c"

using namespace CodeEasyAvr;
void LedBlinkPerDelayVariableMs(Task * task)
{
	if (BlinkFlag)
	{
		if (ledCounter > 700)
		{
			ledCounter = 0;
			YellowLed.Toggle();
		}
		++ledCounter;
	}
	else
	{
		YellowLed.Set();
	}
}
void KeyboardHandler(Task * task)
{
	if (!Button.Check()) //Atmega has only internal pull ups - so button must be setted (1), and button must ground it. If pin == 0 then is pressed
	{
		++ButtonPressTime;
	}
	else 
	{
		if (ButtonPressTime > 220)
		{
			str_t_bfr_cpy(ButtonPressTime/100,TextOk);//Bad
			BlinkFlag = !BlinkFlag;
		}
		else if (ButtonPressTime > 15)
		{
			str_t_bfr_cpy(5,TextOk);//Bad
			GreenLed.Toggle();
		}
			ButtonPressTime = 0;
	}
}
void Led(Task * task){

		if (elapsedTime == 16)
			LCD_GoTo(0,1);
		
		if (elapsedTime == 33)
		{
			LCD_GoTo(0,0);
			elapsedTime = 0;
		}
	
		LCD_WriteData(LedBuffer[elapsedTime]);
		elapsedTime++;
}

void RegisterTasks()
{
	taskName.currentMethod = LedBlinkPerDelayVariableMs;
	Taskmanager.Register(taskName);

	keyboardTask.currentMethod = KeyboardHandler;
	Taskmanager.Register(keyboardTask);

	Leds.currentMethod = Led;
	Taskmanager.Register(Leds);
	}
void static EnableAsync()
{
  //2000 instructions per task - 1ms task resolution CAREFULL: Exit mail will erase interrupt SREG
	Timer0::SetCompareValue(7); // Why 7? When we get 16mhz, divide it 8 (8 tasks), we get 2mhz, divide it 8*256 its 2048 - 1 ms -
	Timer0::WaveFormMode(Timer0::WaveForms::CTC);
	Timer0::SetInterrupts(CodeEasyAvr::Timer0::CompareMatchInterrupt);
	Timer0::SetPrescaler(Timer0::Prescalers::Prescaler_256);
	sei();
}
void LCD_Setup() 
{
	LCD_Initalize();
	LCD_Home();
}
void InitializeProgram()
{
	LCD_Setup();
	Button.AsInput();

	Button.Set();

	 GreenLed.FastAsOutput();
	   RedLed.FastAsOutput();
	YellowLed.FastAsOutput();

	 GreenLed.FastSet();
	   RedLed.FastSet();
	YellowLed.FastSet();
	RegisterTasks();
	EnableAsync();
}

int main()
{
	InitializeProgram();
	while(1)
	{	
	}
}	//Important, if program get out of main SREG bit will be cleared!

