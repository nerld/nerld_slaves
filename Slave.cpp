#include "Slave.h"

Slave::Slave() {}
Slave::Slave(int addr, int type) : m_address(addr), m_type(type) {}
int Slave::execute(int val) {
	return val;
}

