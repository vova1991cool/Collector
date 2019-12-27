// 
// 
// 

#include "ROMPlugin.h"

bool ROMPluginClass::init()
{
	EEPROM.begin(DATA_SIZE);
	Serial.print("Reading 0 bit: ");
	Serial.println(EEPROM.read(0));
	if (EEPROM.read(0) != 0) {
		_data = DataConteiner();
		_data.printAll(Serial);
		return true;
	}
	return false;
}

void ROMPluginClass::cleanAllROM()
{
	EEPROM.begin(1024);
	for (int i = 0; i < 1024; i++) {
		EEPROM.write(i, 0);
	}
	EEPROM.commit();
	EEPROM.end();
}


ROMPluginClass ROMPlugin;

DataConteiner::DataConteiner()
{
	deserializeJson(jDoc, EEPROM);
}

void DataConteiner::printAll(Stream &destinition)
{
	serializeJson(jDoc, destinition);
	destinition.println();
}

const char * DataConteiner::operator[](uint8_t id)
{
	return jDoc[strKeys[id]];
}

void DataConteiner::setEl(uint8_t id, uint8_t value)
{
	jDoc[strKeys[id]] = value;
}
void DataConteiner::setEl(uint8_t id, char *value)
{
	jDoc[strKeys[id]] = value;
}

void DataConteiner::commit()
{
	serializeJson(jDoc, EEPROM);
	EEPROM.commit();
}
