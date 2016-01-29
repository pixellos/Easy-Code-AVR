/* 
* Async.h
*
* Created: 29/01/2016 11:31:15
* Author: rogoz
*/

#define _atmega16a_
#include <avr/interrupt.h>
#include <avr/io.h>

  #define CLEAR(toClear, val) toClear &= ~(val)
  #define SET(toSet,val) toSet |= val
  //I want to use

  typedef void ( * Action)();


/*
Let's do some math:
about 16000000 asm instruction per sec 
Prescaler 256
*/

#ifndef __ASYNC_H__
#define __ASYNC_H__
class Task{
private:

public:
int AlocateNumber;
Action currentMethod = nullptr;
Action chainedMethod = nullptr;

};
#pragma message("DO NOT USE TIMER/COUNTER0!! It's managed by Async Static Class - If you change something this definitly wont work!")
using namespace CodeEasyAvr;

class Async
{
public:
	void static StartAsync(){ // 2000 instructions per task - 1ms task resolution CAREFULL: Exit mail will erase interrupt SREG
	
	Timer0::SetPrescaler(Timer0::Prescalers::Prescaler_256);
	Timer0::SetCompareValue(8); // Why 8? When we get 16mhz, divide it 8 (8 tasks), we get 2mhz, divide it 8*256 its 1024 - 
	Timer0::WaveFormMode(Timer0::WaveForms::CTC);
		
	Timer0::SetInterrupts(CodeEasyAvr::Timer0::CompareMatchInterrupt);


		sei();

	TCNT0 = 0;
	}
		
		//Fixed time version
	class TaskManager{
	private:
	static const uint8_t NumberOfActions = 8;
	public:
		Action actions[NumberOfActions];
		uint8_t currentTask;
		TaskManager()
		{
			currentTask = 0;
			for (size_t i = 0; i < NumberOfActions; i++)
			{
				actions[i] = nullptr;
			}
		}

void GetNext()
{
	++currentTask;
	if (currentTask >= NumberOfActions)
	{
		currentTask = 0;
	}
}

void Invoke()
{
	if (actions[currentTask] != nullptr)
	{
		(actions[currentTask])();
	}
	GetNext();
}

void Register(Task& task)
{
	uint8_t firstFreeIndicator = 0;

	for (; firstFreeIndicator < NumberOfActions; ++firstFreeIndicator)
	{
		if (actions[firstFreeIndicator] == nullptr)
		{
			break;//out of range
		}
	}

	if (firstFreeIndicator >= NumberOfActions)
	{
		return; //Sorry, this wont be registered :/
	}
	//Ok, now we have first free action, and it isnt out of range. We can register it
	UnsafeRegister(task, firstFreeIndicator);
}



void UnsafeRegister(Task& task, uint8_t positionIndicator)
{
	actions[positionIndicator] = (task.currentMethod);
	task.AlocateNumber = positionIndicator;
}//Potentialy dangerous -


void UnsafeUnregister(Task& task)
{
	actions[task.AlocateNumber] = nullptr;
	task.AlocateNumber = 255;
}

	};
}; //Async

#endif //__ASYNC_H__
