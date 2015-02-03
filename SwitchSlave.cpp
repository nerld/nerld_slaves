#include "SwitchSlave.h"


SwitchSlave::SwitchSlave(int addr) : Slave(addr, SWITCH), m_currentState(0) 
{}

SwitchSlave::SwitchSlave() {}

int SwitchSlave::toggle() {
	Wire.requestFrom(m_address,1);
  while(Wire.available()) {
  	int state = Wire.read();
  	m_currentState = state;
  	Serial.print("Current State is: ");
    Serial.println(m_currentState);
  }
}