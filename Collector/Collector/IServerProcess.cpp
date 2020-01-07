// 
// 
// 

#include "IServerProcess.h"

void IServerProcessClass::init()
{
	WiFi.mode(DataManager.get());
	char _ssid[21], _pass[21];
	DataManager.get(_ssid, _pass);
	if (WiFi.getMode() == WIFI_AP) {
		WiFi.softAP(_ssid, _pass);
	}
	else {
		Serial.print("Try to connect.");
		WiFi.begin(_ssid, _pass);
		while (WiFi.status() != WL_CONNECTED)
		{
			Serial.print(".");
		}
	}
	char _host[21];
	Serial.println(MDNS.begin(DataManager.get(_host, true)) ? "mDNS responder started" : "Error setting up MDNS responder!");
	
	_server.on("/", HTTP_GET, []() {
		IServerProcess.sendPage();
	});

	_server.on("/save", HTTP_POST, []() {

	});

}

IServerProcessClass IServerProcess;
