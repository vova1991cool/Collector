/*
 Name:		Collector.ino
 Created:	11.12.2019 14:28:15
 Author:	vova1
*/

// the setup function runs once when you press reset or power the board
#include <EEPROM.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServerSecure.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.hpp>
#include <ArduinoJson.h>
#include "ISetHendler.h"
#include "IServerProcess.h"
#include "IGsmHandler.h"

#define GSM_RX 14
#define GSM_TX 12

SoftwareSerial gsm(GSM_RX, GSM_TX);

void setup() {
	Serial.begin(9600);
	Serial.println("Start!");
	gsm.begin(9600);
	gsm.println("AT");
}

// the loop function runs over and over again until power down or reset
void loop() {
	if (gsm.available())
		Serial.write(gsm.read());
	if (Serial.available())
		gsm.write(Serial.read());
}
