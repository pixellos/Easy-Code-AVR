#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>
#include "CppHelpers.h"
#include "SPL/Avr5Lib.hpp"
#include "SPL/Atmega16A_SPL.hpp"
#include "TaskManager/TaskManager.hpp"
#include "Variables.h"

class SingleButton // Button connected to gnd
{
	private:
	PinSBase * _ButtonPin;
	volatile uint16_t _PressTime;
	Action _ClickAction = nullptr;
	Action _HoldAction = nullptr;
	public:
	const uint8_t MinClickTime = 15;
	const uint8_t MinHoldTime = 220;
	SingleButton(PinSBase &pin, Action click,Action hold)
	{
		_ButtonPin = &pin;
		_ButtonPin->AsInput();
		_ButtonPin->Set();
		_PressTime = 0;
		_ClickAction = click;
		_HoldAction = hold;
	}

	void CheckButtonState()
	{
		if (!_ButtonPin->Check()) //Atmega has only internal pull ups - so button must be setted (1), and button must ground it. If pin == 0 then is pressed
		{
			++_PressTime;
		}
		else
		{
			if (_PressTime > MinHoldTime)
			{
				_HoldAction();
			}
			else if (_PressTime > MinClickTime)
			{
				_ClickAction();
			}
			_PressTime = 0;
		}
	}
};

void firstButtonClick()
{
	GreenLed.Toggle();
}

void firstButtonHold()
{
	BlinkFlag = !BlinkFlag;
}


void secondButtonClick()
{
	RedLed.Set();
	debugDisplay.Enable();
}

void secondButtonHold()
{
	RedLed.Clear();
	debugDisplay.Disable();
}

SingleButton firstButton(Button,firstButtonClick,firstButtonHold);
SingleButton secondButton(OtherButton,secondButtonClick,secondButtonHold);

void static EnableAsync()
{
	Timer0::SetCompareValue(7); // Why 7? When we get 16mhz, divide it 8 (8 tasks), we get 2mhz, divide it 8*256 its 2048 - 1 ms -
	Timer0::WaveFormMode(Timer0::WaveForms::CTC);
	Timer0::SetInterrupts(CodeEasyAvr::Timer0::CompareMatchInterrupt);
	Timer0::SetPrescaler(Timer0::Prescalers::Prescaler_256);
	sei();
}

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
	firstButton.CheckButtonState();
	secondButton.CheckButtonState();
}

void RegisterTasks()
{
	taskName.currentMethod = LedBlinkPerDelayVariableMs;
	Taskmanager.Register(taskName);
	keyboardTask.currentMethod = KeyboardHandler;
	Taskmanager.Register(keyboardTask);
}

void InitializePorts()
{
		 GreenLed.AsOutput();
		 RedLed.AsOutput();
		 YellowLed.AsOutput();
		 GreenLed.Set();
		 RedLed.Set();
		 YellowLed.Set();
}

void InitializeProgram()
{
	InitializePorts();
	debugDisplay.Initialize();
	RegisterTasks();
	EnableAsync();
}

int main()
{
	InitializeProgram();
	while("forever")
	{
		debugDisplay.PrintDebugMessage();
		debugDisplay.TryClear();
	}
}
