#pragma message("DO NOT USE TIMER/COUNTER0!! It's managed by Async Static Class - If you change something this definitly wont work! ")
#pragma message("It's vaild for 16MHZ - if you have less set your own Timer0 Compare Value and Prescaler to get 1/8ms per tick")
#pragma message("You must implement EnableAsync - template is before end of file MultiTasking.hpp")

//#define StandardTasks
#define ChainingTasks

#ifndef __MULTITASKING_H__
	#define __MULTITASKING_H__
	class Task;
	class TaskManager;

	#ifdef ChainingTasks
		typedef  void(*Action)(Task*);
		#include "MainAsyncChainedTaskManager.cpp"
	#endif

	#ifdef StandardTasks
		typedef void(*Action)();
		#include "MainAsyncTaskManager.cpp"
	#endif
	static TaskManager Taskmanager;

	ISR(TIMER0_COMP_vect)
	{
		Taskmanager.Invoke();
	}
#endif 

//Static time
//8 task + main loop
//void static MultiTasking::EnableAsync(/*You must enable interrupts )
/*{ // 2000 instructions per task - 1ms task resolution CAREFULL: Exit mail will erase interrupt SREG
	Timer0::SetCompareValue(7); // Why 7? When we get 16mhz, divide it 8 (8 tasks), we get 2mhz, divide it 8*256 its 2048 - 1 ms -
	Timer0::WaveFormMode(Timer0::WaveForms::CTC);
	Timer0::SetInterrupts(CodeEasyAvr::Timer0::CompareMatchInterrupt);
	Timer0::SetPrescaler(Timer0::Prescalers::Prescaler_256);
	sei();
}
	ISR(TIMER0_COMP_vect){
		MultiTasker.Invoke();
	}*/

//Version 2 - flag at Compare, Invoke at forever loop - 8 task 
/*
static bool MultiTaskFlag = false
	ISR(TIMER0_COMP_vect){
		MultiTaskFlag = true;
	}
	int main()
	{
	//Some stuff
	while(1)
	{
		if(MultiTaskFlag)
		{
			MultiTaskFlag = false;
			MultiTasker.Invoke();
		}
	}
}
*/