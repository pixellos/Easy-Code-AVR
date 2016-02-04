/*
 * Avr5Lib.hpp
 *  Author: Pixello
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>

#define CLEAR(toClear, val) toClear &= ~(uint8_t)(val)
#define SET(toSet,val) toSet |= (uint8_t)val

namespace CodeEasyAvr{
	class SPI;
	class Timer0;
}
 
 #ifndef _AVR_5LIB__
 #define _AVR_5LIB__
#include "Avr5Lib.cpp"

#endif