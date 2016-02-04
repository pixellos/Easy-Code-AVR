
class DisplaySH1106{
	private:
	const static uint16_t buforSize = 512;
	uint8_t screenBufor[buforSize];

	void displayInitialize(uint8_t refresh,uint8_t contrast)
	{
		DCPin.Clear();
		//Tons of lov level command - thanks Piotr!
		WaitAndNextSendData(SH1106_DISPLAYOFF);
		WaitAndNextSendData(SH1106_SETMULTIPLEX);
		WaitAndNextSendData(0x3F);
		WaitAndNextSendData(SH1106_SETSTARTLINE);        /*set display start line*/
		WaitAndNextSendData(SH1106_PAGEADDR);   		 	/*set page address*/
		WaitAndNextSendData(SH1106_SETLOWCOLUMN|0x02);	/*set lower column address*/
		WaitAndNextSendData(SH1106_SETHIGHCOLUMN);    	/*set higher column address*/
		WaitAndNextSendData(SH1106_SEGREMAP|0x01); 		/*set segment remap*/
		WaitAndNextSendData(SH1106_NORMALDISPLAY);    	/*normal / reverse*/
		WaitAndNextSendData(SH1106_CHARGEPUMP);			/*set charge pump enable*/
		WaitAndNextSendData(SH1106_MEMORYMODE);
		WaitAndNextSendData(0x00);
		WaitAndNextSendData(SH1106_EXTERNALVCC);			/*external VCC   */
		WaitAndNextSendData(0x31);  						/*0X30---0X33  7,4V-8V-8,4V-9V */
		_delay_ms(10);
		WaitAndNextSendData(SH1106_COMSCANDEC);    		/*Com scan direction*/
		WaitAndNextSendData(SH1106_SETDISPLAYOFFSET);    /*set display offset*/
		WaitAndNextSendData(0x00);   						/*   0x20  /   0x00 */
		WaitAndNextSendData(SH1106_SETDISPLAYCLOCKDIV);  /*set osc division*/
		WaitAndNextSendData(refresh);
		WaitAndNextSendData(SH1106_SETPRECHARGE);    	/*set pre-charge period*/
		WaitAndNextSendData(0x1f);    					/*0x22  /  0x1f*/
		WaitAndNextSendData(SH1106_SETCOMPINS);    		/*set COM pins*/
		WaitAndNextSendData(0x12);
		WaitAndNextSendData(SH1106_SETVCOMDETECT);    	/*set vcomh*/
		WaitAndNextSendData(0x40);
		WaitAndNextSendData(SH1106_SETCONTRAST);
		WaitAndNextSendData(contrast);
		WaitAndNextSendData(SH1106_DISPLAYALLON_RESUME);
		WaitAndNextSendData(SH1106_NORMALDISPLAY);
		WaitAndNextSendData(SH1106_DISPLAYON);
		BuforClear();
	}

	void SendPartOfBufor(uint8_t AtBuferPosition,uint8_t PacketsAtPack, uint8_t LineIndicator)
	{
		DCPin.Clear();
		WaitAndNextSendData (LineIndicator);
		WaitAndNextSendData (SH1106_SETHIGHCOLUMN);
		DCPin.Set();
		for(uint8_t i=0; i < PacketsAtPack; ++i)
		{
			WaitAndNextSendData(screenBufor[i]+AtBuferPosition);
		}
	}
	public:

	enum class DataCategory{
		Command=0,
		Data = 1,
	};
	void SendSynchronous(uint8_t byteFrame,const DataCategory dataCategory)//2x speed, 2 cycles per data send, 1600(16 mhz 1 task )/16
	{
		//CS HIGH
		DCPin.BoolSet((bool)dataCategory);
		SPI::SetData(byteFrame);
	}
	void SendBuforSynchronous()
	{
		DCPin.Clear();
		WaitAndNextSendData(SH1106_SETLOWCOLUMN);

		for (uint8_t i = 0; i < 4; ++i)
		{
			SendPartOfBufor(128*i,128,0xB0+i);
		}
	}
	void BuforClear()
	{
		memset(screenBufor,0,buforSize);
	}
	void InitializeSyncronous()//Synchronous version - dont place it inside task!!!!!!!!!!!!!!!1
	{
		MosiPin.FastAsOutput();
		SckPin.FastAsOutput();
		DCPin.FastAsOutput();
		ResetPin.FastAsOutput();

		ResetPin.Set();
		_delay_ms(50);
		ResetPin.Clear();
		_delay_ms(50);
		ResetPin.Set();

		//DIRxSET = CS; //


		SPI::SpiMode3();
		SPI::AsMaster();
		SPI::SPIEnable();

		displayInitialize(10,10);
	}

	void WaitAndNextSendData(uint8_t byteFrame)
	{
		SPI::SetData(byteFrame);
	}
};
