/*AUTO GENERATED CODE BY MATEUSZ POPIELARZ pixdevlife.azurewebsites.net
            Project Easy::CodeGenerator
            */
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

 #define  __FAST__PIN__OPERATIONS__ENABLE
 #ifndef __OPTIMIZE__
 #pragma message"Compiler optimizations disabled; functions from CodeLessAvr -> FastSet, FastClear wont work as designed! At -o3 OOP have only a bit program speed overhead"
#endif
 #pragma message "This Fast operations are compiler optimalizable	!"

 template<const volatile uint8_t PortAddress,const volatile uint8_t PinAddress,const volatile uint8_t DdrAddress,const volatile uint8_t NOPin>
 class PinS
        {
            public:
	 #ifdef __FAST__PIN__OPERATIONS__ENABLE
	 void FastSet()
            {
                (*(uint8_t*)PortAddress) |= (1 << NOPin); //Result is single SBI() in asm when only 1 set, at other case compiler will make it 3x1 cycles asm instrucions
            }

            void FastClear()
            {
                (*(uint8_t*)PortAddress) &= ~(1 << NOPin);
            }

            void FastToggle()
            {
                *(uint8_t*)PortAddress ^= (1 << NOPin);
            }

            void FastAsOutput()
            {
                *(uint8_t*)DdrAddress |= (1 << NOPin);
            }

            void FastAsInput()
            {
                *(uint8_t*)DdrAddress &= !(1 << NOPin);
            }
#endif
			volatile void BoolSet(bool value)
			{	
				if (value)
				{
					Set();
				}
				else
				{
					Clear();
				}
			}

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
                *(uint8_t volatile*)PortAddress ^= (1 << NOPin);
            }

            volatile bool Check()
            {
                return ((*(uint8_t volatile*)PinAddress >> NOPin) &1);
            }

            volatile void AsOutput()
            {
                *(uint8_t volatile *)DdrAddress |= (1 << NOPin);
            }

            volatile void AsInput()
            {
                *(uint8_t volatile*)DdrAddress &= !(1 << NOPin);
            }
        };



 