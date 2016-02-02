/*
* Async.h
*
* Created: 29/01/2016 11:31:15
* Author: rogoz
*/
#include <avr/interrupt.h>
#include <avr/io.h>

typedef void (*Action)();
#define __FIXED_TIME_ASYNC__
//#define __


#ifndef __ASYNC_H__
#define __ASYNC_H__

class Task{
public:
	int AlocateNumber;
	Action currentMethod = nullptr;
	Action chainedMethod = nullptr;
};

#pragma message("DO NOT USE TIMER/COUNTER0!! It's managed by Async Static Class - If you change something this definitly wont work! ")
#pragma message("It's vaild for 16MHZ - if you have less set your own Timer0 Compare Value and Prescaler to get 1/8ms per tick")

using namespace CodeEasyAvr;

class Async{
public:
	void static EnableAsync(/*You must enable interrupts*/)
	{ // 2000 instructions per task - 1ms task resolution CAREFULL: Exit mail will erase interrupt SREG
		Timer0::SetCompareValue(7); // Why 7? When we get 16mhz, divide it 8 (8 tasks), we get 2mhz, divide it 8*256 its 2048 - 1 ms -
		Timer0::WaveFormMode(Timer0::WaveForms::CTC);
		Timer0::SetInterrupts(CodeEasyAvr::Timer0::CompareMatchInterrupt);
		Timer0::SetPrescaler(Timer0::Prescalers::Prescaler_256);
	}

	//Fixed time version
	class TaskManager{
	public:
		static const uint8_t NumberOfActions = 8;


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

		void UnsafeRegister(Task& task, uint8_t positionIndicator)
		{
			actions[positionIndicator] = (task.currentMethod);
			task.AlocateNumber = positionIndicator;
		}//Potentialy dangerous - do not use it unless you dont know what are you doing

		void UnsafeUnregister(Task& task)
		{
			actions[task.AlocateNumber] = nullptr;
			task.AlocateNumber = 255;
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

	};
}; //Async

Async::TaskManager taskManager;

ISR (TIMER0_COMP_vect)
{
	taskManager.Invoke();
}
#endif //__ASYNC_H__

