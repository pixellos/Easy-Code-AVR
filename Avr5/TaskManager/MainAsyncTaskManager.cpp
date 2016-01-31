#include <avr/interrupt.h>
#include <inttypes.h>
#include <stdlib.h>

class Task;
typedef void(*Action)();

class Task
{
	public:
	int AlocateNumber;//Dont set it by hand! only for test purposes
	Action currentMethod = nullptr;

};

class TaskManager
{
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



	/*private:
		static const uint8_t NumberOfTasks = 8;
		Task* tasks[NumberOfTasks];
		uint8_t currentTaskNumber;
		
		void UnsafeRegister(Task& task, uint8_t positionIndicator)
		{
			tasks[positionIndicator] = &task;
			task.AlocateNumber = positionIndicator;
		}
	public:
		TaskManager()
		{
			currentTaskNumber = 0;
			for (size_t i = 0; i < NumberOfTasks; i++)
			{
				tasks[i] = nullptr;
			}
		}

		

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
			while (tasks[firstFreeIndicator] != nullptr)
			{
				firstFreeIndicator++;
			}

			if (firstFreeIndicator < NumberOfTasks)
			{
				UnsafeRegister(task, firstFreeIndicator);
			}
		}*/
	};
	static TaskManager Taskmanager;
