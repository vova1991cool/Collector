// 
// 
// 

#include "IServerProcess.h"

void IServerProcessClass::init(DataConteiner *_data)
{
	WiFi.mode(_data->get());

}

IServerProcessClass IServerProcess;
