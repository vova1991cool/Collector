// IGsmHandler.h

#ifndef _IGSMHANDLER_h
#define _IGSMHANDLER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "SoftwareSerial.h"

#define PHONESIZE 11

class GsmHendlerClass :public SoftwareSerial
{
private:
	char phoneNum[PHONESIZE];
	uint8_t recordID;
	void dial();
	void hangUp();
	void configureModem();
	void getCurrentCallState();
public:
	GsmHendlerClass(uint8_t rxpin, uint8_t txpin, char *phone, uint8_t _recordID)
		:SoftwareSerial(rxpin, txpin, false, 256U), recordID(_recordID) {
		strcpy(phoneNum, phone);
	};



};

#endif

