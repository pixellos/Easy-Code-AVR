

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

        uint8_t static Check()
       {
            return PINA;
       }
        void static AsOutput()
       {
            DDRA &= ~(0xff);
       }

        void static AsInputBits()
       {
            DDRA |= 0xff;
       }
        void static AsOutputBits(uint8_t uCharValue)
       {
            DDRA &= ~(uCharValue);
       }

        void static AsInputBits(uint8_t uCharValue)
       {
            DDRA |= uCharValue;
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

	    bool Check()
	    {
		    return ((PINA >> 0) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRA &= ~(1<<0);
	    }

	    void static AsInput()
	    {
		    DDRA |= 1<<0;
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

	    bool Check()
	    {
		    return ((PINA >> 1) & 1);
	    }

	    void static AsOutput()
	    {
		    DDRA &= ~(1<<1);
	    }

	    void static AsInput()
	    {
		    DDRA |= 1<<1;
	    }
        };