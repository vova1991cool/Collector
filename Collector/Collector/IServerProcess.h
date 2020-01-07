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


 public:
	void init(DataConteiner*);
};

extern IServerProcessClass IServerProcess;

#endif

