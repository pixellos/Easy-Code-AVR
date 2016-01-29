// Async Mock.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <time.h>
#include <io.h>
#include <iostream>
#include <cstdint>

#pragma once


typedef void (*Action)();
void Write()
{
	std::cout << "Jestem";
}

class Task
{
public:
	int AlocateNumber;//Dont set it by hand! only for test purposes
	Action currentMethod = nullptr;
	Action chainedMethod = nullptr;
};
#pragma message("DO NOT USE TIMER/COUNTER0!! It's managed by Async Static Class - If you change something this definitly wont work!")

class Async
{
public:
	void static StartAsync()
	{ // 2000 instructions per task - 1ms task resolution
		/*init
		Timer0::SetPrescaler(Timer0::Prescalers::Prescaler_256);
		Timer0::SetCompareValue = 8; // Why 8? When we get 16mhz, divide it 8 (8 tasks), we get 2mhz, divide it 8*256 its 1024 - 
		Timer0::SetInterrupts(Timer0::Interrupt::CompareMatchInterrupt);
		sei();
		*/
	}

	//Fixed time version
	class TaskManager
	{
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
};




Async::TaskManager *taskManager = new Async::TaskManager();
Task *task = new Task();

void Initialize()
{

	(*task).currentMethod= &Write;
	(*taskManager).Register(*task);
}

void AtTimerCount()
{
	(*taskManager).Invoke();
}

void IntMock()
{
	Initialize();
	int starttime = clock();//1000
	while (1)
	{
		int time = clock();
		if (time > (starttime + 50))
		{
			starttime = time;
			AtTimerCount();
		}
	}
}

int main()
{
	IntMock();
}
