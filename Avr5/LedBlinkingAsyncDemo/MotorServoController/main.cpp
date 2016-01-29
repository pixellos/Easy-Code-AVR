#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "avrpindef.h"
#include "Avr5Lib.cpp"
#define F_CPU 16000000
#include "util/delay.h"
#include "Async.h"

void * operator new(size_t size)
{
	return malloc(size);
}

void operator delete(void * ptr)
{
	free(ptr);
}
using namespace CodeEasyAvr; 

Async::TaskManager taskmanager;

ISR(TIMER0_COMP_vect){
taskmanager.Invoke();
	TCNT0 = 0;
}

class Funny{
public:
	static void Blink(int ms){

	Pin_B1::Set();
	_delay_ms(ms/8);

	Pin_B1::Clear();
	_delay_ms(ms);
	}
};


Timer0 timer0;
volatile static int16_t ledCounter = 0;
volatile static int16_t DelayMs = 100;


void LedBlinkPerDelayVariableMs(){
++ledCounter;
	if (ledCounter > 5)
	{
		ledCounter = 0;
		Pin_B1::Toggle();
	}
}




int main(){

	Pin_B0::Clear();
	Pin_B0::AsOutput();
	Pin_B1::AsOutput();

	Task task;
	task.currentMethod = &LedBlinkPerDelayVariableMs;
	taskmanager.Register(task);

	Async::StartAsync();




	while(1);

}
