// 
// 
// 

#include "ISetHendler.h"

DataConteiner::DataConteiner()
{
	EEPROM.begin(DATA_SIZE);
	Serial.print("Reading 0 bit: ");
	Serial.println(EEPROM.read(0));
	if (EEPROM.read(0) == 0) {
		setDefaults();
	}
	deserializeJson(jDoc, EEPROM);
}

void DataConteiner::setDefaults()
{
	EEPROM.put(0, DEF_SET);
	EEPROM.commit();
	delay(500);
	EEPROM.end();
	resetFunc();
}
