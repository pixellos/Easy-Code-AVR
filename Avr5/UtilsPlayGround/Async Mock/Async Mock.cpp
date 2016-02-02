// Async Mock.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <time.h>
#include <io.h>
#include <iostream>
#include <cstdint>

class Task;
typedef void(*TaskAction)(Task*);

template<int in>
class MyClass
{
public:
	int s = in;
};

class Task
{
public:
	int AlocateNumber;//Dont set it by hand! only for test purposes
	TaskAction currentMethod = nullptr;
	void Invoke()
	{
		currentMethod(this);
	}
};

void First(Task *task);
void Second(Task *task);

void First(Task *task)
{
	std::cout << "First";
	task->currentMethod = Second;
}

void Second(Task *task)
{
	std::cout << "Second";
	task->currentMethod = First;
}

void Write()
{
	std::cout << "Write";
}

	class TaskManager {
	public:
		static const uint8_t NumberOfTasks = 8;

		Task* tasks[NumberOfTasks];
		uint8_t currentTaskNumber;

		TaskManager()
		{
			currentTaskNumber = 0;
			for (size_t i = 0; i < NumberOfTasks; i++)
			{
				tasks[i] = nullptr;
			}
		}
		void UnsafeRegister(Task& task, uint8_t positionIndicator)
		{
			tasks[positionIndicator] = &task;
			task.AlocateNumber = positionIndicator;
		}//Potentialy dangerous - do not use it unless you dont know what are you doing

		void UnsafeUnregister(Task* task)
		{
			tasks[task->AlocateNumber] = nullptr;
		}

		void GetNext()
		{
			++currentTaskNumber;
			if (currentTaskNumber >= NumberOfTasks)
			{
				currentTaskNumber = 0;
			}
		}
		void Invoke()
		{
			if (tasks[currentTaskNumber] != nullptr)
			{
				tasks[currentTaskNumber]->Invoke();
			}
			GetNext();
		}

		void Register(Task& task)
		{
			uint8_t firstFreeIndicator = 0;

			for (; firstFreeIndicator < NumberOfTasks; ++firstFreeIndicator)
			{
				if (tasks[firstFreeIndicator] == nullptr)
				{
					break;//out of range
				}
			}

			if (firstFreeIndicator >= NumberOfTasks)
			{
				return; //Sorry, this wont be registered :/
			}
			//Ok, now we have first free action, and it isnt out of range. We can register it
			UnsafeRegister(task, firstFreeIndicator);
		}
	};


TaskManager *taskManager = new TaskManager();
Task *task = new Task();

Task *task1 = new Task();

void Initialize()
{
	(*task).currentMethod = First;
	task1->currentMethod = First;
	(*taskManager).Register(*task1);
	(*taskManager).Register(*task);
	(*taskManager).Register(*task1);
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
	//IntMock();
}
