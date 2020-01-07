// IServerProcess.h

#ifndef _ISERVERPROCESS_h
#define _ISERVERPROCESS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "ISetHendler.h"

class IServerProcessClass:public ESP8266WebServer
{
 public:
	void init();
	void clientsHendler() { this->handleClient(); }
};

extern IServerProcessClass IServerProcess;

#endif

