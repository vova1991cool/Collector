// ROMPlugin.h

#ifndef _ROMPLUGIN_h
#define _ROMPLUGIN_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "EEPROM.h"
#include "ArduinoJson.h"

#define DATA_SIZE 256
#define _SSID "ESP8266Default"
#define _PASS "12345678"
#define _UDP_IP "192.168.0.66"
#define _UDP_PORT 1066

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#endif

static const char *strKeys[] = { "SSID", "PASS", "IP", "PORT", "PHONE_NUM", "recordID" };

enum SettingsDescrEnum
{
	SSID,
	PASS,
	IP,
	PORT,
	PHONE_NUM,
	recordID
}settingsID;


struct DataConteiner
{
	StaticJsonDocument<DATA_SIZE> jDoc;

	DataConteiner();

	void printAll(Stream &destinition);

	const char* operator[](uint8_t);

	void setEl(uint8_t, uint8_t);
	void setEl(uint8_t, char*);

	void commit();
};

class ROMPluginClass
{
 private:
	 DataConteiner _data;
	 WiFiUDP _udp;
	 bool _status;

 public:
	bool init();
	void udpSender(char *data);
	void udpListener();
	void cleanAllROM();
};

extern ROMPluginClass ROMPlugin;

#endif

