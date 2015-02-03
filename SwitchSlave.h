#ifndef SWITCH_SLAVE_H
#define SWITCH_SLAVE_H
#define SWITCH 0
#define SERVO 1
#define MOTOR 2
#include "Arduino.h"
#include <Wire.h>
#include "Slave.h"


class SwitchSlave : public Slave {
public:
	int m_currentState;
	SwitchSlave();
	SwitchSlave(int addr);
	int toggle();
};


#endif