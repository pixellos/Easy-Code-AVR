/*AUTO GENERATED CODE BY MATEUSZ POPIELARZ pixdevlife.azurewebsites.net
            Project Easy::CodeGenerator
            */
			/*
class Base{};

template<uint8_t Ddr,uint8_t Port,uint8_t Pins, uint8_t PinNum>
class Pin : public Base
{
public:
	static uint8_t DDR = Ddr;
	static uint8_t PORT = Port;
	static uint8_t PIN = Pins;
	static uint8_t PinNumber = PinNum;
};


class Pin_A0:public Pin<PORTA,PINA,DDRA,0>{
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

class Pin_A1:public Pin<PORTA,PINA,DDRA,1>{
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

class Pin_A2:public Pin<PORTA,PINA,DDRA,2>{
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

class Pin_A3:public Pin<PORTA,PINA,DDRA,3>{
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

class Pin_A4:public Pin<PORTA,PINA,DDRA,4>{
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

class Pin_A5:public Pin<PORTA,PINA,DDRA,5>{
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

class Pin_A6:public Pin<PORTA,PINA,DDRA,6>{
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

class Pin_A7:public Pin<PORTA,PINA,DDRA,7>{
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

class Pin_B0:public Pin<PORTB,PINB,DDRB,0>{
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

class Pin_B1:public Pin<PORTB,PINB,DDRB,1>{
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

class Pin_B2:public Pin<PORTB,PINB,DDRB,2>{
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

class Pin_B3:public Pin<PORTB,PINB,DDRB,3>{
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

class Pin_B4:public Pin<PORTB,PINB,DDRB,4>{
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

class Pin_B5:public Pin<PORTB,PINB,DDRB,5>{
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

class Pin_B6:public Pin<PORTB,PINB,DDRB,6>{
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

class Pin_B7:public Pin<PORTB,PINB,DDRB,7>{
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

class Pin_C0:public Pin<PORTC,PINC,DDRC,0>{
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

class Pin_C1:public Pin<PORTC,PINC,DDRC,1>{
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

class Pin_C2:public Pin<PORTC,PINC,DDRC,2>{
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

class Pin_C3:public Pin<PORTC,PINC,DDRC,3>{
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

class Pin_C4:public Pin<PORTC,PINC,DDRC,4>{
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

class Pin_C5:public Pin<PORTC,PINC,DDRC,5>{
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

class Pin_C6:public Pin<PORTC,PINC,DDRC,6>{
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

class Pin_C7:public Pin<PORTC,PINC,DDRC,7>{
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

class Pin_D0:public Pin<PORTD,PIND,DDRD,0>{
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

class Pin_D1:public Pin<PORTD,PIND,DDRD,1>{
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

class Pin_D2:public Pin<PORTD,PIND,DDRD,2>{
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

class Pin_D3:public Pin<PORTD,PIND,DDRD,3>{
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
}

class Pin_D4:public Pin<PORTD,PIND,DDRD,4>{
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

class Pin_D5:public Pin<PORTD,PIND,DDRD,5>{
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

class Pin_D6:public Pin<PORTD,PIND,DDRD,6>{
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

class Pin_D7:public Pin<PORTD,PIND,DDRD,7>{
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
}*/