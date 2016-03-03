/*
 * Atmega8.cpp
 *
 * Created: 03/03/2016 19:25:05
 * Author : rogoz
 */ 

#include <avr/io.h>
#include "mega8SPL.h"

void static EnableAsync()
{
	//Must be 2MHZ to get 1 ms at atmega 8
	Timer0::SetInterrupts(CodeEasyAvr::Timer0::OverFlowInterrupt);
	Timer0::SetPrescaler(Timer0::Prescalers::Prescaler_256);
	
	sei();
}


int main(void)
{

}

