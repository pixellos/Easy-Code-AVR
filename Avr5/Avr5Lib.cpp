/*
 * Avr5Lib.cpp
 *Sandbox for testing 
 * Created: 28/01/2016 12:19:21
 *  Author: rogoz
 */ 

 //Tons of static code beacuse avr5 are slow, and it must be full compilator optimalizable

 #define _atmega16a_
 #include <avr/io.h>
  #define CLEAR(toClear, val) toClear &= ~(val)
  #define SET(toSet,val) toSet |= val

 namespace CodeEasyAvr{
 	  enum Prescalers {
		  Stop,
	 	  Prescaler_1,
	 	  Prescaler_8,
	 	  Prescaler_64,
	 	  Prescaler_256,
	 	  Prescaler_1024,
		  External_Falling,
		  External_Rising
 	  };

 	  enum WaveForms{
	 	  Normal = 0,
	 	  PWM_PhaseCorrect = WGM00,
	 	  CTC = (WGM00||WGM01),
	 	  PWM_Fast = WGM01
 	  };

		enum OutputCounterMode{
			Disconnected = 0,
			Toggle_Or_Reserved = COM00,
			Clear = COM01,
			Set = COM00,
	  };

 //8bit Timer/Counter0 with PWM
	class Timer0{
		public:
  /*Bad WAY
  class WaveForm{
  public:
		void static Normal(){
		CLEAR(TCCR0,(WGM01||WGM00));
		}

		void static CTC(){
		Normal();
		SET(TCCR0,WGM01);
		}

  };*/
		static void WaveFormMode(WaveForms waveForms){
			CLEAR(TCCR0,WGM01||WGM00);
			SET(TCCR0,waveForms);
		}

		static void CompareMatchOutput(OutputCounterMode outputCounterMode){
			CLEAR(TCCR0,COM01||COM00);
			SET(TCCR0,outputCounterMode);
		};
};
}