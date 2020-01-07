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

static const char *strKeys[] = { "SSID", "PASS", "IP", "PHONE_NUM" };

enum SettingsDescrEnum
{
	SSID = 1,
	PASS,
	IP,
	PHONE_NUM
}settingsID;

enum WirelesModes
{
	AP,
	STA
}WiFiStates;

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

	const WirelesModes getMode() { return jDoc["MODE"]; }

	const uint8_t getRecordID() { return jDoc["RECORD_ID"]; }

	void printAll(Stream &destinition) {
		serializeJson(jDoc, destinition);
		destinition.println();
	}

	const char* operator[](SettingsDescrEnum id) { return jDoc[strKeys[id]]; }

	void setEl(SettingsDescrEnum id, char* value) {
		jDoc[strKeys[id]] = value;
		serializeJson(jDoc, EEPROM);
	}

	void setDefaults();
};

#endif

