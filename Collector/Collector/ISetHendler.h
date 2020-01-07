// ISetHendler.h

#ifndef _ISETHENDLER_h
#define _ISETHENDLER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "EEPROM.h"
#include "ArduinoJson.h"

#define DATA_SIZE 256
#define DEF_SET "{\"MODE\":0,\"SSID\":\"ESP8266Default\",\"PASS\":\"12345678\",\"IP\":\"192.168.0.66\",\"PHONE_NUM\":\"0965622167\",\"RECORD_ID\":0}"

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESP8266WebServerSecure.h>
#include <ESP8266WebServer.h>
#endif

static void(*resetFunc) (void) = 0;

class DataConteiner
{
private:
	StaticJsonDocument<DATA_SIZE> jDoc;

public:

	DataConteiner();
	~DataConteiner()
	{
		EEPROM.commit();
		EEPROM.end();
	}

	void printAll(Stream &destinition) {
		serializeJson(jDoc, destinition);
		destinition.println();
	}

	void get(IPAddress &_ip) { _ip.fromString(jDoc["IP"].as<const char*>()); }
	WiFiMode get() { return WiFiMode(jDoc["MODE"]); }
	void get(char *_ssid, char *_pass) { strcpy(_ssid, jDoc["SSID"]); strcpy(_pass, jDoc["PASS"]); }
	void get(char *_num) { strcpy(_num, jDoc["PHONE_NUM"]); }
	void get(uint8_t &_recID) { _recID = jDoc["RECORD_ID"]; }

	void setEl(char* key, char* value) {
		jDoc[key] = value;
		serializeJson(jDoc, EEPROM);
	}

	void setDefaults();
};

#endif

