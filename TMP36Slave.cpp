#include "TMP36Slave.h"


TMP36Slave::TMP36Slave(int addr) : Slave(addr, TMP36), m_delay(1000) 
{}

TMP36Slave::TMP36Slave() {}

int TMP36Slave::execute(int val) {
	m_delay = val;
	String commandString = String(val);;
	char buffer[11];
	commandString.toCharArray(buffer, 11);
	Serial.println(buffer);
	Wire.beginTransmission(1);
	Wire.write(buffer);
	Wire.endTransmission();
}