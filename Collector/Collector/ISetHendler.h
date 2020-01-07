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
#define DEF_SET "{\"MODE\":0,\"SSID\":\"ESP8266Default\",\"PASS\":\"12345678\",\"HOST\":\"GSMDefault\",\"PHONE_NUM\":\"0965622167\",\"RECORD_ID\":0}"
#define HTML_PAGE "HTML"

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#endif

static void(*resetFunc) (void) = 0;

class DataConteiner
{
private:
	StaticJsonDocument<DATA_SIZE> jDoc;

public:

	void init();

	void printAll(Stream &destinition) {
		serializeJson(jDoc, destinition);
		destinition.println();
	}

	char* get(char *_dataAdr, bool isHost = false) { return strcpy(_dataAdr, jDoc[isHost?"HOST":"PHONE_NUM"]); }
	WiFiMode get() { return WiFiMode(jDoc["MODE"]); }
	void get(char *_ssid, char *_pass) { strcpy(_ssid, jDoc["SSID"]); strcpy(_pass, jDoc["PASS"]); }
	void get(uint8_t &_recID) { _recID = jDoc["RECORD_ID"]; }
	const char* _getPreparedPage();

	void setEl(char* key, char* value) {
		jDoc[key] = value;
		serializeJson(jDoc, EEPROM);
	}

	void setDefaults();
};

extern DataConteiner DataManager;

#endif

