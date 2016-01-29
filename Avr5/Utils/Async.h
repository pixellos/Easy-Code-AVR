/* 
* Async.h
*
* Created: 29/01/2016 11:31:15
* Author: rogoz
*/

#define _atmega16a_
#include <avr/interrupt.h>
#include <avr/io.h>
#include "Avr5Lib.cpp"

  #define CLEAR(toClear, val) toClear &= ~(val)
  #define SET(toSet,val) toSet |= val
  //I want to use

  typedef void ( * Action)();

ISR(TIMER0_COMP_vect){
	//Here


}

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
	void static StartAsync(){ // 2000 instructions per task - 1ms task resolution
	Timer0::SetPrescaler(Timer0::Prescalers::Prescaler_256);
	Timer0::SetCompareValue = 8; // Why 8? When we get 16mhz, divide it 8 (8 tasks), we get 2mhz, divide it 8*256 its 1024 - 
	Timer0::SetInterrupts(Timer0::Interrupt::CompareMatchInterrupt);
	sei();
	}
		
		//Fixed time version
	class TaskManager{
	private:
	static uint8_t NumberOfActions = 8;
	volatile static Action * actions[NumberOfActions] = {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr};
	volatile static uint8_t currentTask = 0;
	public:
	void static GetNext(){
	++currentTask;
		if (currentTask >= NumberOfActions)
		{
			currentTask = 0;
		}
		
	}

	void static Invoke(){
		if (actions[currentTask]!= nullptr)
		{	
			(actions[currentTask])();
		}
		GetNext();
	}

	//Bad idea - there's need of dynamic alocation 
		void static Register(Task &task){
		uint8_t firstFreeIndicator = 0;
	
		for (; firstFreeIndicator < NumberOfActions;++firstFreeIndicator)
		{
			if (actions[firstFreeIndicator]==nullptr)
			{
				break; 
			}
		}
		if (firstFreeIndicator >= NumberOfActions)
		{
			return; //Sorry, this wont be registered :/
		}
			//Ok, now we have first free action, and it isnt out of range. We can register it
		UnsafeRegister(task,firstFreeIndicator);
		}
	};

	void static UnsafeRegister(Task &task, uint8_t positionIndicator){
			actions[positionIndicator] = (*task).chainedMethod;
			(*task).AlocateNumber = positionIndicator;
	}//Potentialy dangerous - 
	
	void static UnsafeUnregister(Task &task){

	}
	
	Async();
	~Async();
}; //Async

#endif //__ASYNC_H__
