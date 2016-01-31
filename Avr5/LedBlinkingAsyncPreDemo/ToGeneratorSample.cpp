///

#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

 #define  __FAST__PIN__OPERATIONS__ENABLE
 #ifdef __FAST__PIN__OPERATIONS__ENABLE
 #ifndef __OPTIMIZE__
 #pragma message "Compiler optimizations disabled; functions from CodeLessAvr -> FastSet, FastClear wont work as designed! At -o3 OOP have 0 Performance overhead " 
 #endif
  #endif

 template<const volatile uint8_t PortAddress,const volatile uint8_t PinAddress,const volatile uint8_t DdrAddress,const volatile uint8_t NOPin>
 class PinS
 {
	 public:
	 #ifdef __FAST__PIN__OPERATIONS__ENABLE
	 void FastSet()
	 {
		 (*(uint8_t *)PortAddress) |= (1 << NOPin); //Result is single SBI() in asm when only 1 set, at other case compiler will make it 3x1 cycles asm instrucions
	 }

	 void FastClear()
	 {
		 (*(uint8_t *)PortAddress) &= ~(1 << NOPin);
	 }

	 void FastToggle()
	 {
		 *(uint8_t *)PortAddress ^= (1<<NOPin);
	 }

	 void FastAsOutput()
	 {
		 *(uint8_t *)DdrAddress |= (1<<NOPin);
	 }

	 void FastAsInput()
	 {
		 *(uint8_t *)DdrAddress &= !(1<<NOPin);
	 }
	 #endif

	 volatile void Set()
	 {
		 (*(uint8_t volatile*)PortAddress) |= (1 << NOPin); //Result is single SBI() in asm (2 cycles)
	 }

	 void Clear()
	 {
		 (*(uint8_t volatile*)PortAddress) &= ~(1 << NOPin);
	 }

	 volatile void Toggle()
	 {
		 *(uint8_t volatile*)PortAddress ^= (1<<NOPin);
	 }

	 volatile bool Check()
	 {
		 return ((*(uint8_t volatile*)PinAddress >> NOPin) & 1);
	 }

	 volatile void AsOutput()
	 {
		 *(uint8_t volatile *)DdrAddress |= (1<<NOPin);
	 }

	 volatile void AsInput()
	 {
		 *(uint8_t volatile*)DdrAddress &= !(1<<NOPin);
	 }
 };


 typedef PinS<(uint8_t)0x3B,(uint8_t)0x39,0x3A,1> _PinA1;
 typedef PinS<(uint8_t)0x3B,(uint8_t)0x39,0x3A,2> _PinA2;

