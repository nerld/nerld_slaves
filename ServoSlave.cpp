#include "ServoSlave.h"


ServoSlave::ServoSlave(int addr) : Slave(addr, SERVO), m_currentState(0) 
{}

ServoSlave::ServoSlave() {}

int ServoSlave::execute(int val) {
	writeServo(val);
	m_currentState = val;
}

int ServoSlave::writeServo(int angle) {
  Wire.beginTransmission(m_address);
  Wire.write(angle);
  Wire.endTransmission();
}