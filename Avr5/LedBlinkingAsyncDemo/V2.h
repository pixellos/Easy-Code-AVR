/*AUTO GENERATED CODE BY MATEUSZ POPIELARZ pixdevlife.azurewebsites.net
            Project Easy::CodeGenerator
            */
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

 #define  __FAST__PIN__OPERATIONS__ENABLE
 #ifdef __FAST__PIN__OPERATIONS__ENABLE
 #ifndef __OPTIMIZE__
 #pragma message"Compiler optimizations disabled; functions from CodeLessAvr -> FastSet, FastClear wont work as designed! At -o3 OOP have 0 Performance overhead"
#endif
 #pragma message "This Fast operations are compiler optimalizable - they're not atomic - care about it!"
 #endif

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



 typedef PinS<(uint8_t)59,(uint8_t)57,(uint8_t)58,(uint8_t)0> PIN_A0;
                                PIN_A0 Pin_A0;


 typedef PinS<(uint8_t)59,(uint8_t)57,(uint8_t)58,(uint8_t)1> PIN_A1;
                                PIN_A1 Pin_A1;


 typedef PinS<(uint8_t)59,(uint8_t)57,(uint8_t)58,(uint8_t)2> PIN_A2;
                                PIN_A2 Pin_A2;


 typedef PinS<(uint8_t)59,(uint8_t)57,(uint8_t)58,(uint8_t)3> PIN_A3;
                                PIN_A3 Pin_A3;


 typedef PinS<(uint8_t)59,(uint8_t)57,(uint8_t)58,(uint8_t)4> PIN_A4;
                                PIN_A4 Pin_A4;


 typedef PinS<(uint8_t)59,(uint8_t)57,(uint8_t)58,(uint8_t)5> PIN_A5;
                                PIN_A5 Pin_A5;


 typedef PinS<(uint8_t)59,(uint8_t)57,(uint8_t)58,(uint8_t)6> PIN_A6;
                                PIN_A6 Pin_A6;


 typedef PinS<(uint8_t)59,(uint8_t)57,(uint8_t)58,(uint8_t)7> PIN_A7;
                                PIN_A7 Pin_A7;


 typedef PinS<(uint8_t)56,(uint8_t)54,(uint8_t)55,(uint8_t)0> PIN_B0;
                                PIN_B0 Pin_B0;


 typedef PinS<(uint8_t)56,(uint8_t)54,(uint8_t)55,(uint8_t)1> PIN_B1;
                                PIN_B1 Pin_B1;


 typedef PinS<(uint8_t)56,(uint8_t)54,(uint8_t)55,(uint8_t)2> PIN_B2;
                                PIN_B2 Pin_B2;


 typedef PinS<(uint8_t)56,(uint8_t)54,(uint8_t)55,(uint8_t)3> PIN_B3;
                                PIN_B3 Pin_B3;


 typedef PinS<(uint8_t)56,(uint8_t)54,(uint8_t)55,(uint8_t)4> PIN_B4;
                                PIN_B4 Pin_B4;


 typedef PinS<(uint8_t)56,(uint8_t)54,(uint8_t)55,(uint8_t)5> PIN_B5;
                                PIN_B5 Pin_B5;


 typedef PinS<(uint8_t)56,(uint8_t)54,(uint8_t)55,(uint8_t)6> PIN_B6;
                                PIN_B6 Pin_B6;


 typedef PinS<(uint8_t)56,(uint8_t)54,(uint8_t)55,(uint8_t)7> PIN_B7;
                                PIN_B7 Pin_B7;


 typedef PinS<(uint8_t)53,(uint8_t)51,(uint8_t)52,(uint8_t)0> PIN_C0;
                                PIN_C0 Pin_C0;


 typedef PinS<(uint8_t)53,(uint8_t)51,(uint8_t)52,(uint8_t)1> PIN_C1;
                                PIN_C1 Pin_C1;


 typedef PinS<(uint8_t)53,(uint8_t)51,(uint8_t)52,(uint8_t)2> PIN_C2;
                                PIN_C2 Pin_C2;


 typedef PinS<(uint8_t)53,(uint8_t)51,(uint8_t)52,(uint8_t)3> PIN_C3;
                                PIN_C3 Pin_C3;


 typedef PinS<(uint8_t)53,(uint8_t)51,(uint8_t)52,(uint8_t)4> PIN_C4;
                                PIN_C4 Pin_C4;


 typedef PinS<(uint8_t)53,(uint8_t)51,(uint8_t)52,(uint8_t)5> PIN_C5;
                                PIN_C5 Pin_C5;


 typedef PinS<(uint8_t)53,(uint8_t)51,(uint8_t)52,(uint8_t)6> PIN_C6;
                                PIN_C6 Pin_C6;


 typedef PinS<(uint8_t)53,(uint8_t)51,(uint8_t)52,(uint8_t)7> PIN_C7;
                                PIN_C7 Pin_C7;


 typedef PinS<(uint8_t)50,(uint8_t)48,(uint8_t)49,(uint8_t)0> PIN_D0;
                                PIN_D0 Pin_D0;


 typedef PinS<(uint8_t)50,(uint8_t)48,(uint8_t)49,(uint8_t)1> PIN_D1;
                                PIN_D1 Pin_D1;


 typedef PinS<(uint8_t)50,(uint8_t)48,(uint8_t)49,(uint8_t)2> PIN_D2;
                                PIN_D2 Pin_D2;


 typedef PinS<(uint8_t)50,(uint8_t)48,(uint8_t)49,(uint8_t)3> PIN_D3;
                                PIN_D3 Pin_D3;


 typedef PinS<(uint8_t)50,(uint8_t)48,(uint8_t)49,(uint8_t)4> PIN_D4;
                                PIN_D4 Pin_D4;


 typedef PinS<(uint8_t)50,(uint8_t)48,(uint8_t)49,(uint8_t)5> PIN_D5;
                                PIN_D5 Pin_D5;


 typedef PinS<(uint8_t)50,(uint8_t)48,(uint8_t)49,(uint8_t)6> PIN_D6;
                                PIN_D6 Pin_D6;


 typedef PinS<(uint8_t)50,(uint8_t)48,(uint8_t)49,(uint8_t)7> PIN_D7;
                                PIN_D7 Pin_D7;
