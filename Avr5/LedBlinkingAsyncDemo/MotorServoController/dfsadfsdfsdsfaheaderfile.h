/*AUTO GENERATED CODE BY MATEUSZ POPIELARZ pixdevlife.azurewebsites.net*/

    class PortA{
        public:
	    void static SetBits(uint8_t uCharValue)
       {
            PORTA |= uCharValue;
       }
        
        void static Set()
       {
            PORTA = 0xff;
       }

        void static ClearBits(uint8_t uCharValue)
       {
            PORTA &= ~(uCharValue);
       }

         void static Clear()
       {
            PORTA = 0;
       }

        void static ToggleBits(uint8_t uCharValue)
       {
            PORTA ^= uCharValue;
       }
        void static Toggle()
       {
            PORTA ^= 0xff;
       }

        bool static Check()
       {
            return PINA;
       }
        
        void static AsOutput()
       {
            DDRA = 0xff;
       }
        void static AsInput()
       {
            DDRA = 0;
       }

        void static AsOutputBits(uint8_t uCharValue)
       {
            DDRA |= (uCharValue);
       }

        void static AsInputBits(uint8_t uCharValue)
       {
            DDRA &= ~uCharValue;
       }
       };

    class Pin_A0{
public:
	    void static Set()
	    {
		    PORTA |= 1 << 0;
	    }

	    void static Clear()
	    {
		    PORTA &= ~(1<<0);
	    }

	    void static Toggle()
	    {
		    PORTA ^= (1<<0);
	    }

	    bool static Check()
	    {
		    return ((PINA >> 0) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRA |= (1<<0);
	    }

	    void static AsInput()
	    {
		    DDRA &= !(1<<0);
	    }
        };

    class Pin_A1{
public:
	    void static Set()
	    {
		    PORTA |= 1 << 1;
	    }

	    void static Clear()
	    {
		    PORTA &= ~(1<<1);
	    }

	    void static Toggle()
	    {
		    PORTA ^= (1<<1);
	    }

	    bool static Check()
	    {
		    return ((PINA >> 1) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRA |= (1<<1);
	    }

	    void static AsInput()
	    {
		    DDRA &= !(1<<1);
	    }
        };

    class Pin_A2{
public:
	    void static Set()
	    {
		    PORTA |= 1 << 2;
	    }

	    void static Clear()
	    {
		    PORTA &= ~(1<<2);
	    }

	    void static Toggle()
	    {
		    PORTA ^= (1<<2);
	    }

	    bool static Check()
	    {
		    return ((PINA >> 2) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRA |= (1<<2);
	    }

	    void static AsInput()
	    {
		    DDRA &= !(1<<2);
	    }
        };

    class Pin_A3{
public:
	    void static Set()
	    {
		    PORTA |= 1 << 3;
	    }

	    void static Clear()
	    {
		    PORTA &= ~(1<<3);
	    }

	    void static Toggle()
	    {
		    PORTA ^= (1<<3);
	    }

	    bool static Check()
	    {
		    return ((PINA >> 3) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRA |= (1<<3);
	    }

	    void static AsInput()
	    {
		    DDRA &= !(1<<3);
	    }
        };

    class Pin_A4{
public:
	    void static Set()
	    {
		    PORTA |= 1 << 4;
	    }

	    void static Clear()
	    {
		    PORTA &= ~(1<<4);
	    }

	    void static Toggle()
	    {
		    PORTA ^= (1<<4);
	    }

	    bool static Check()
	    {
		    return ((PINA >> 4) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRA |= (1<<4);
	    }

	    void static AsInput()
	    {
		    DDRA &= !(1<<4);
	    }
        };

    class Pin_A5{
public:
	    void static Set()
	    {
		    PORTA |= 1 << 5;
	    }

	    void static Clear()
	    {
		    PORTA &= ~(1<<5);
	    }

	    void static Toggle()
	    {
		    PORTA ^= (1<<5);
	    }

	    bool static Check()
	    {
		    return ((PINA >> 5) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRA |= (1<<5);
	    }

	    void static AsInput()
	    {
		    DDRA &= !(1<<5);
	    }
        };

    class Pin_A6{
public:
	    void static Set()
	    {
		    PORTA |= 1 << 6;
	    }

	    void static Clear()
	    {
		    PORTA &= ~(1<<6);
	    }

	    void static Toggle()
	    {
		    PORTA ^= (1<<6);
	    }

	    bool static Check()
	    {
		    return ((PINA >> 6) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRA |= (1<<6);
	    }

	    void static AsInput()
	    {
		    DDRA &= !(1<<6);
	    }
        };

    class Pin_A7{
public:
	    void static Set()
	    {
		    PORTA |= 1 << 7;
	    }

	    void static Clear()
	    {
		    PORTA &= ~(1<<7);
	    }

	    void static Toggle()
	    {
		    PORTA ^= (1<<7);
	    }

	    bool static Check()
	    {
		    return ((PINA >> 7) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRA |= (1<<7);
	    }

	    void static AsInput()
	    {
		    DDRA &= !(1<<7);
	    }
        };

    class PortB{
        public:
	    void static SetBits(uint8_t uCharValue)
       {
            PORTB |= uCharValue;
       }
        
        void static Set()
       {
            PORTB = 0xff;
       }

        void static ClearBits(uint8_t uCharValue)
       {
            PORTB &= ~(uCharValue);
       }

         void static Clear()
       {
            PORTB = 0;
       }

        void static ToggleBits(uint8_t uCharValue)
       {
            PORTB ^= uCharValue;
       }
        void static Toggle()
       {
            PORTB ^= 0xff;
       }

        bool static Check()
       {
            return PINB;
       }
        
        void static AsOutput()
       {
            DDRB = 0xff;
       }
        void static AsInput()
       {
            DDRB = 0;
       }

        void static AsOutputBits(uint8_t uCharValue)
       {
            DDRB |= (uCharValue);
       }

        void static AsInputBits(uint8_t uCharValue)
       {
            DDRB &= ~uCharValue;
       }
       };

    class Pin_B0{
public:
	    void static Set()
	    {
		    PORTB |= 1 << 0;
	    }

	    void static Clear()
	    {
		    PORTB &= ~(1<<0);
	    }

	    void static Toggle()
	    {
		    PORTB ^= (1<<0);
	    }

	    bool static Check()
	    {
		    return ((PINB >> 0) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRB |= (1<<0);
	    }

	    void static AsInput()
	    {
		    DDRB &= !(1<<0);
	    }
        };

    class Pin_B1{
public:
	    void static Set()
	    {
		    PORTB |= 1 << 1;
	    }

	    void static Clear()
	    {
		    PORTB &= ~(1<<1);
	    }

	    void static Toggle()
	    {
		    PORTB ^= (1<<1);
	    }

	    bool static Check()
	    {
		    return ((PINB >> 1) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRB |= (1<<1);
	    }

	    void static AsInput()
	    {
		    DDRB &= !(1<<1);
	    }
        };

    class Pin_B2{
public:
	    void static Set()
	    {
		    PORTB |= 1 << 2;
	    }

	    void static Clear()
	    {
		    PORTB &= ~(1<<2);
	    }

	    void static Toggle()
	    {
		    PORTB ^= (1<<2);
	    }

	    bool static Check()
	    {
		    return ((PINB >> 2) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRB |= (1<<2);
	    }

	    void static AsInput()
	    {
		    DDRB &= !(1<<2);
	    }
        };

    class Pin_B3{
public:
	    void static Set()
	    {
		    PORTB |= 1 << 3;
	    }

	    void static Clear()
	    {
		    PORTB &= ~(1<<3);
	    }

	    void static Toggle()
	    {
		    PORTB ^= (1<<3);
	    }

	    bool static Check()
	    {
		    return ((PINB >> 3) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRB |= (1<<3);
	    }

	    void static AsInput()
	    {
		    DDRB &= !(1<<3);
	    }
        };

    class Pin_B4{
public:
	    void static Set()
	    {
		    PORTB |= 1 << 4;
	    }

	    void static Clear()
	    {
		    PORTB &= ~(1<<4);
	    }

	    void static Toggle()
	    {
		    PORTB ^= (1<<4);
	    }

	    bool static Check()
	    {
		    return ((PINB >> 4) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRB |= (1<<4);
	    }

	    void static AsInput()
	    {
		    DDRB &= !(1<<4);
	    }
        };

    class Pin_B5{
public:
	    void static Set()
	    {
		    PORTB |= 1 << 5;
	    }

	    void static Clear()
	    {
		    PORTB &= ~(1<<5);
	    }

	    void static Toggle()
	    {
		    PORTB ^= (1<<5);
	    }

	    bool static Check()
	    {
		    return ((PINB >> 5) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRB |= (1<<5);
	    }

	    void static AsInput()
	    {
		    DDRB &= !(1<<5);
	    }
        };

    class Pin_B6{
public:
	    void static Set()
	    {
		    PORTB |= 1 << 6;
	    }

	    void static Clear()
	    {
		    PORTB &= ~(1<<6);
	    }

	    void static Toggle()
	    {
		    PORTB ^= (1<<6);
	    }

	    bool static Check()
	    {
		    return ((PINB >> 6) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRB |= (1<<6);
	    }

	    void static AsInput()
	    {
		    DDRB &= !(1<<6);
	    }
        };

    class Pin_B7{
public:
	    void static Set()
	    {
		    PORTB |= 1 << 7;
	    }

	    void static Clear()
	    {
		    PORTB &= ~(1<<7);
	    }

	    void static Toggle()
	    {
		    PORTB ^= (1<<7);
	    }

	    bool static Check()
	    {
		    return ((PINB >> 7) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRB |= (1<<7);
	    }

	    void static AsInput()
	    {
		    DDRB &= !(1<<7);
	    }
        };

    class PortC{
        public:
	    void static SetBits(uint8_t uCharValue)
       {
            PORTC |= uCharValue;
       }
        
        void static Set()
       {
            PORTC = 0xff;
       }

        void static ClearBits(uint8_t uCharValue)
       {
            PORTC &= ~(uCharValue);
       }

         void static Clear()
       {
            PORTC = 0;
       }

        void static ToggleBits(uint8_t uCharValue)
       {
            PORTC ^= uCharValue;
       }
        void static Toggle()
       {
            PORTC ^= 0xff;
       }

        bool static Check()
       {
            return PINC;
       }
        
        void static AsOutput()
       {
            DDRC = 0xff;
       }
        void static AsInput()
       {
            DDRC = 0;
       }

        void static AsOutputBits(uint8_t uCharValue)
       {
            DDRC |= (uCharValue);
       }

        void static AsInputBits(uint8_t uCharValue)
       {
            DDRC &= ~uCharValue;
       }
       };

    class Pin_C0{
public:
	    void static Set()
	    {
		    PORTC |= 1 << 0;
	    }

	    void static Clear()
	    {
		    PORTC &= ~(1<<0);
	    }

	    void static Toggle()
	    {
		    PORTC ^= (1<<0);
	    }

	    bool static Check()
	    {
		    return ((PINC >> 0) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRC |= (1<<0);
	    }

	    void static AsInput()
	    {
		    DDRC &= !(1<<0);
	    }
        };

    class Pin_C1{
public:
	    void static Set()
	    {
		    PORTC |= 1 << 1;
	    }

	    void static Clear()
	    {
		    PORTC &= ~(1<<1);
	    }

	    void static Toggle()
	    {
		    PORTC ^= (1<<1);
	    }

	    bool static Check()
	    {
		    return ((PINC >> 1) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRC |= (1<<1);
	    }

	    void static AsInput()
	    {
		    DDRC &= !(1<<1);
	    }
        };

    class Pin_C2{
public:
	    void static Set()
	    {
		    PORTC |= 1 << 2;
	    }

	    void static Clear()
	    {
		    PORTC &= ~(1<<2);
	    }

	    void static Toggle()
	    {
		    PORTC ^= (1<<2);
	    }

	    bool static Check()
	    {
		    return ((PINC >> 2) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRC |= (1<<2);
	    }

	    void static AsInput()
	    {
		    DDRC &= !(1<<2);
	    }
        };

    class Pin_C3{
public:
	    void static Set()
	    {
		    PORTC |= 1 << 3;
	    }

	    void static Clear()
	    {
		    PORTC &= ~(1<<3);
	    }

	    void static Toggle()
	    {
		    PORTC ^= (1<<3);
	    }

	    bool static Check()
	    {
		    return ((PINC >> 3) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRC |= (1<<3);
	    }

	    void static AsInput()
	    {
		    DDRC &= !(1<<3);
	    }
        };

    class Pin_C4{
public:
	    void static Set()
	    {
		    PORTC |= 1 << 4;
	    }

	    void static Clear()
	    {
		    PORTC &= ~(1<<4);
	    }

	    void static Toggle()
	    {
		    PORTC ^= (1<<4);
	    }

	    bool static Check()
	    {
		    return ((PINC >> 4) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRC |= (1<<4);
	    }

	    void static AsInput()
	    {
		    DDRC &= !(1<<4);
	    }
        };

    class Pin_C5{
public:
	    void static Set()
	    {
		    PORTC |= 1 << 5;
	    }

	    void static Clear()
	    {
		    PORTC &= ~(1<<5);
	    }

	    void static Toggle()
	    {
		    PORTC ^= (1<<5);
	    }

	    bool static Check()
	    {
		    return ((PINC >> 5) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRC |= (1<<5);
	    }

	    void static AsInput()
	    {
		    DDRC &= !(1<<5);
	    }
        };

    class Pin_C6{
public:
	    void static Set()
	    {
		    PORTC |= 1 << 6;
	    }

	    void static Clear()
	    {
		    PORTC &= ~(1<<6);
	    }

	    void static Toggle()
	    {
		    PORTC ^= (1<<6);
	    }

	    bool static Check()
	    {
		    return ((PINC >> 6) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRC |= (1<<6);
	    }

	    void static AsInput()
	    {
		    DDRC &= !(1<<6);
	    }
        };

    class Pin_C7{
public:
	    void static Set()
	    {
		    PORTC |= 1 << 7;
	    }

	    void static Clear()
	    {
		    PORTC &= ~(1<<7);
	    }

	    void static Toggle()
	    {
		    PORTC ^= (1<<7);
	    }

	    bool static Check()
	    {
		    return ((PINC >> 7) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRC |= (1<<7);
	    }

	    void static AsInput()
	    {
		    DDRC &= !(1<<7);
	    }
        };

    class PortD{
        public:
	    void static SetBits(uint8_t uCharValue)
       {
            PORTD |= uCharValue;
       }
        
        void static Set()
       {
            PORTD = 0xff;
       }

        void static ClearBits(uint8_t uCharValue)
       {
            PORTD &= ~(uCharValue);
       }

         void static Clear()
       {
            PORTD = 0;
       }

        void static ToggleBits(uint8_t uCharValue)
       {
            PORTD ^= uCharValue;
       }
        void static Toggle()
       {
            PORTD ^= 0xff;
       }

        bool static Check()
       {
            return PIND;
       }
        
        void static AsOutput()
       {
            DDRD = 0xff;
       }
        void static AsInput()
       {
            DDRD = 0;
       }

        void static AsOutputBits(uint8_t uCharValue)
       {
            DDRD |= (uCharValue);
       }

        void static AsInputBits(uint8_t uCharValue)
       {
            DDRD &= ~uCharValue;
       }
       };

    class Pin_D0{
public:
	    void static Set()
	    {
		    PORTD |= 1 << 0;
	    }

	    void static Clear()
	    {
		    PORTD &= ~(1<<0);
	    }

	    void static Toggle()
	    {
		    PORTD ^= (1<<0);
	    }

	    bool static Check()
	    {
		    return ((PIND >> 0) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRD |= (1<<0);
	    }

	    void static AsInput()
	    {
		    DDRD &= !(1<<0);
	    }
        };

    class Pin_D1{
public:
	    void static Set()
	    {
		    PORTD |= 1 << 1;
	    }

	    void static Clear()
	    {
		    PORTD &= ~(1<<1);
	    }

	    void static Toggle()
	    {
		    PORTD ^= (1<<1);
	    }

	    bool static Check()
	    {
		    return ((PIND >> 1) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRD |= (1<<1);
	    }

	    void static AsInput()
	    {
		    DDRD &= !(1<<1);
	    }
        };

    class Pin_D2{
public:
	    void static Set()
	    {
		    PORTD |= 1 << 2;
	    }

	    void static Clear()
	    {
		    PORTD &= ~(1<<2);
	    }

	    void static Toggle()
	    {
		    PORTD ^= (1<<2);
	    }

	    bool static Check()
	    {
		    return ((PIND >> 2) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRD |= (1<<2);
	    }

	    void static AsInput()
	    {
		    DDRD &= !(1<<2);
	    }
        };

    class Pin_D3{
public:
	    void static Set()
	    {
		    PORTD |= 1 << 3;
	    }

	    void static Clear()
	    {
		    PORTD &= ~(1<<3);
	    }

	    void static Toggle()
	    {
		    PORTD ^= (1<<3);
	    }

	    bool static Check()
	    {
		    return ((PIND >> 3) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRD |= (1<<3);
	    }

	    void static AsInput()
	    {
		    DDRD &= !(1<<3);
	    }
        };

    class Pin_D4{
public:
	    void static Set()
	    {
		    PORTD |= 1 << 4;
	    }

	    void static Clear()
	    {
		    PORTD &= ~(1<<4);
	    }

	    void static Toggle()
	    {
		    PORTD ^= (1<<4);
	    }

	    bool static Check()
	    {
		    return ((PIND >> 4) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRD |= (1<<4);
	    }

	    void static AsInput()
	    {
		    DDRD &= !(1<<4);
	    }
        };

    class Pin_D5{
public:
	    void static Set()
	    {
		    PORTD |= 1 << 5;
	    }

	    void static Clear()
	    {
		    PORTD &= ~(1<<5);
	    }

	    void static Toggle()
	    {
		    PORTD ^= (1<<5);
	    }

	    bool static Check()
	    {
		    return ((PIND >> 5) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRD |= (1<<5);
	    }

	    void static AsInput()
	    {
		    DDRD &= !(1<<5);
	    }
        };

    class Pin_D6{
public:
	    void static Set()
	    {
		    PORTD |= 1 << 6;
	    }

	    void static Clear()
	    {
		    PORTD &= ~(1<<6);
	    }

	    void static Toggle()
	    {
		    PORTD ^= (1<<6);
	    }

	    bool static Check()
	    {
		    return ((PIND >> 6) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRD |= (1<<6);
	    }

	    void static AsInput()
	    {
		    DDRD &= !(1<<6);
	    }
        };

    class Pin_D7{
public:
	    void static Set()
	    {
		    PORTD |= 1 << 7;
	    }

	    void static Clear()
	    {
		    PORTD &= ~(1<<7);
	    }

	    void static Toggle()
	    {
		    PORTD ^= (1<<7);
	    }

	    bool static Check()
	    {
		    return ((PIND >> 7) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRD |= (1<<7);
	    }

	    void static AsInput()
	    {
		    DDRD &= !(1<<7);
	    }
        };