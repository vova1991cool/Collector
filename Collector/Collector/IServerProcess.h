// IServerProcess.h

#ifndef _ISERVERPROCESS_h
#define _ISERVERPROCESS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "ISetHendler.h"

class IServerProcessClass
{
 private:
	 ESP8266WebServer _server = ESP8266WebServer(80);
 public:
	void init();
	void sendPage() { _server.send(200, "text/html", DataManager._getPreparedPage()); }
};

extern IServerProcessClass IServerProcess;

#endif

