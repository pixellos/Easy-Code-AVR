#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>
#include "CppHelpers.h"
#include "SPL/Avr5Lib.hpp"
#include "SPL/Atmega16A_SPL.hpp"
#include "TaskManager/TaskManager.hpp"
#include "Variables.h"

void NextCalibrateStage()
{
	switch (calibrateStage)
	{
		case CalibrateStage::No:
			calibrateStage = CalibrateStage::Left;

			GreenLed.Clear();
			RedLed.Set();
			
			ICR1 = 0b1111111111;
		break;

		case CalibrateStage::Left:
			
			RedLed.Clear();
			GreenLed.Set();
			
			AS5048AChip.SetZeroPosition();
			calibrateStage = CalibrateStage::Right;
		break;

		case CalibrateStage::Right:
			RedLed.Clear();
			GreenLed.Clear();
			calibrateStage = CalibrateStage::Calibrated;
			RotateLimit = (AS5048AChip.CalculatedPosition);
		break;
		case CalibrateStage::Calibrated:
			calibrateStage = CalibrateStage::No;
		break;
	}
}

void static EnableAsync()
{
	Timer0::SetCompareValue(7); 
	Timer0::WaveFormMode(Timer0::WaveForms::CTC);
	Timer0::SetInterrupts(CodeEasyAvr::Timer0::CompareMatchInterrupt);
	Timer0::SetPrescaler(Timer0::Prescalers::Prescaler_256);
	sei();
}

void ShiftRegisterToMjoyButtonsTranslator()
{
	MjoyButton0.FastSet();
	MjoyButton1.FastSet();
	MjoyButton2.FastSet();
	MjoyButton3.FastSet();
	MjoyButton4.FastSet();
	MjoyButton5.FastSet();
	if ((wheelButtons.lastData) & (1<<8)) {calibrateStage = CalibrateStage::Left; NextCalibrateStage();}
	if ((wheelButtons.lastData) & (1<<7)) {calibrateStage = CalibrateStage::Right; NextCalibrateStage();}
	if ((wheelButtons.lastData) & (1<<11)) {MjoyButton0.Clear();}
	if ((wheelButtons.lastData) & (1<<15)) {MjoyButton1.Clear();}
	if ((wheelButtons.lastData) & (1<<14)) {MjoyButton2.Clear();}
	if ((wheelButtons.lastData) & (1<<13)) {MjoyButton3.Clear();}
	if ((wheelButtons.lastData) & (1<<9)) {MjoyButton4.Clear();}
	if ((wheelButtons.lastData) & (1<<5)) {MjoyButton5.Clear();}
}

void KeyboardTask(Task * task)
{
	wheelButtons.ReadData();
	ShiftRegisterToMjoyButtonsTranslator();
}

void RegisterTasks()
{
	keyboardTask.currentMethod = KeyboardTask;
	Taskmanager.Register(keyboardTask);
}

void PWMInitialize()
{

	PWMOutput.AsOutput();

	Timer1::WaveFormMode(Timer1::WaveFormModes::PhaseCorrect_ICR1);
	Timer1::PWMPhaseCorrectCompareOutputMode(Timer1::PWMPhaseCorrectCompareOutputModes::ClearUpCountingSetDownCounting);
	Timer1::SetPrescaler(Timer1::Prescaler::Prescaler_1);

	ICR1 = 0xffff;
	OCR1A = 0;
}

void ComputePWM()
{
	AS5048AChip.ComputePosition();
	if ( (AS5048AChip.CalculatedPosition) <= RotateLimit)
	{
		OCR1A = (ICR1*((float)AS5048AChip.CalculatedPosition/RotateLimit));
	}
}


void InitializePorts()
{
	PORTD= PORTC = PORTB= DDRB = DDRD =  DDRC = DDRA = 0xff;

	RedLed.AsOutput();
	GreenLed.AsOutput();
}

void InitializeProgram()
{
	InitializePorts();

	#ifdef DebugMode__
	debugDisplay.Enable();
	debugDisplay.Initialize();
	debugDisplay.Disable();
	#endif

	AS5048AChip.Initalize();
	AS5048AChip.Disable();
	#ifdef DebugMode__
	debugDisplay.Enable();
	#endif
	RegisterTasks();
	EnableAsync();
	PWMInitialize();
	wheelButtons.Initialize();
	NextCalibrateStage();
}
#ifdef DebugMode__
void Debug()
{
	debugDisplay.PrintDebugMessage();

	debugDisplay.ChangeActiveLine(6);
	debugDisplay.PrintDataBin(wheelButtons.lastData);

	debugDisplay.ChangeActiveLine(7);
	debugDisplay.PrintDataBin(OCR1A);
}
#endif

int main()
{
	InitializeProgram();
	while("forever")
	{
		ComputePWM();

		#ifdef DebugMode__
		debugDisplay.Enable();
		Debug();
		debugDisplay.Disable();
		#endif
	}
}
