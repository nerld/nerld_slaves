#ifndef SERVO_SLAVE_H
#define SERVO_SLAVE_H
#define SWITCH 0
#define SERVO 1
#define MOTOR 2
#include "Arduino.h"
#include <Wire.h>
#include "Slave.h"


class ServoSlave : public Slave {
public:
	int m_currentState;
	ServoSlave();
	ServoSlave(int addr);
	virtual int execute(int val);

private:
	int writeServo(int angle);
};


#endif