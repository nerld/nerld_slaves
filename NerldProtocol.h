#ifndef NERLD_PROTOCOL_H
#define NERLD_PROTOCOL_H

#include <Wire.h>
#include <HardwareSerial.h>

class NerldProtocol {
public:

	// Constructor
	NerldProtocol();
	NerldProtocol(HardwareSerial *port);

	// Send to Master Module Communication
	int requestAddresssFromMaster();
	int sendCommandToMaster(int slaveAddress, int command, int val);
	int sendCommandToMaster(int slaveAddress, int command, float val);
	int sendCommandToMaster(int slaveAddress, int command, String val);

	// Send to Slave Module Communication
	int requestFromSlave(int slaveAddress);
	int sendCommandToSlave(int slaveAddress, int command, int val);
	int sendCommandToSlave(int slaveAddress, int command, float val);

	// Send to Bridge (from Master only)
	int sendCommandToBridge(int address, int command, int val);

	// Message parsing
	int receiveCommand(int numOfBytes, String * ouput);

	HardwareSerial * m_port;

private:
	// Wire Functions
	void wireTransmit(char * buffer);

	// Encode Message
	int encodeMessage(int address, int command, int value, char * output);
	int encodeMessage(int address, int command, float value, char * output);
	int encodeMessage(int address, int command, String value, char * output);

	// Decode Message
};


#endif