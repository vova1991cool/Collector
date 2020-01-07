// 
// 
// 

#include "IGsmHandler.h"

void GsmHendlerClass::hangUp()
{
	this->println("ATH");
}

void GsmHendlerClass::configureModem()
{
	this->println("ATX3");
	delay(200);
	this->println("AT+CMEE=1");
	delay(200);
}

void GsmHendlerClass::getCurrentCallState()
{
	this->println("AT+CLCC");
	delay(200);
}

