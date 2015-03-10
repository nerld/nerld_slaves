#ifndef TMP36_SLAVE_H
#define TMP36_SLAVE_H
#define SWITCH 0
#define SERVO 1
#define MOTOR 2
#define TMP36 3
#include "Arduino.h"
#include <Wire.h>
#include "Slave.h"


class TMP36Slave : public Slave {
public:
	int m_delay;
	TMP36Slave();
	TMP36Slave(int addr);
	virtual int execute(int val);
};


#endif