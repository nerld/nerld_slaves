#ifndef SLAVE_H
#define SLAVE_H
#define SWITCH 0
#define SERVO 1
#define MOTOR 2
// #include "Arduino.h"


class Slave {
public:
	int m_address;
	int m_type;
	Slave();
	Slave(int addr, int type);
	virtual int execute(int val);
};


#endif