// 
// 
// 

#include "ISetHendler.h"

void DataConteiner::init()
{
	EEPROM.begin(DATA_SIZE);
	Serial.print("Reading 0 bit: ");
	Serial.println(EEPROM.read(0));
	if (EEPROM.read(0) == 0) {
		setDefaults();
	}
	deserializeJson(jDoc, EEPROM);
}

const char * DataConteiner::_getPreparedPage()
{
	return HTML_PAGE;
}

void DataConteiner::setDefaults()
{
	EEPROM.put(0, DEF_SET);
	EEPROM.commit();
	delay(500);
	EEPROM.end();
	resetFunc();
}

DataConteiner DataManager;
