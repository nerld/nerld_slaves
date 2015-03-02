#include "TMP36Slave.h"


TMP36Slave::TMP36Slave(int addr) : Slave(addr, TMP36), m_delay(1000) 
{}

TMP36Slave::TMP36Slave() {}