#include "NerldProtocol.h"

NerldProtocol::NerldProtocol() : m_port(NULL) {}

NerldProtocol::NerldProtocol(HardwareSerial *port) : m_port(port) {}

int NerldProtocol::requestAddresssFromMaster() {
	int address = NULL;
	Wire.requestFrom(1,1);
	while (address == NULL && Wire.available()) {
    address = (Wire.read());
  }
  return address;
}

int NerldProtocol::sendCommandToMaster(int slaveAddress, int command, int val) {
	char encMessage[128];
	if (encodeMessage(slaveAddress, command, val, encMessage) == 0) {
		wireTransmit(encMessage);
		return 0;
	} else {
		return 1;
	}
}

int NerldProtocol::sendCommandToMaster(int slaveAddress, int command, float val) {
	char encMessage[128];
	if (encodeMessage(slaveAddress, command, val, encMessage) == 0) {		
		wireTransmit(encMessage);
		return 0;
	} else {
		return 1;
	}
}

int NerldProtocol::sendCommandToMaster(int slaveAddress, int command, String val) {
	char encMessage[128];
	if (encodeMessage(slaveAddress, command, val, encMessage) == 0) {		
		wireTransmit(encMessage);
		return 0;
	} else {
		return 1;
	}
}

int NerldProtocol::requestFromSlave(int slaveAddress) {
	Wire.requestFrom(slaveAddress,1);
	int retVal = NULL;
  while(Wire.available()) {
  	retVal = Wire.read();
  }
	return retVal;
}

int NerldProtocol::sendCommandToSlave(int slaveAddress, int command, int val) {
	char encMessage[128];
	if (encodeMessage(slaveAddress, command, val, encMessage) == 0) {
		Wire.beginTransmission(slaveAddress);
		Wire.write(encMessage);
		Wire.endTransmission();
		return 0;
	} else {
		return 1;
	}
}

int NerldProtocol::sendCommandToSlave(int slaveAddress, int command, float val) {
	char encMessage[128];
	if (encodeMessage(slaveAddress, command, val, encMessage) == 0) {
		Wire.beginTransmission(slaveAddress);
		Wire.write(encMessage);
		Wire.endTransmission();
		return 0;
	} else {
		return 1;
	}
}

int NerldProtocol::sendCommandToBridge(int address, int command, int val) {
	if (m_port == NULL) {
		return 1;
	}
	char encMessage[128];
	if (encodeMessage(address, command, val, encMessage) == 0) {
		m_port->print(encMessage);

		// parse and return the response from the bridge.

		return 0;
	} else {
		return 1;
	}
}

int NerldProtocol::receiveCommand(int numOfBytes, String * output) {
	for (int j = 0; j < 3; j++) {
		output[j] = "";
	}

	int i = 0;
	int currentArgIdx = 0;
  while(Wire.available() && i < numOfBytes)
  {
    char c = Wire.read();
    
    if (c != ':') {
    	output[currentArgIdx] += c;
    } else {
    	currentArgIdx++;
    }
    i++;
  }

  return 0;
}

void NerldProtocol::wireTransmit(char * buffer) {
	Wire.beginTransmission(1);
	Wire.write(buffer);
	Wire.endTransmission();
}

int NerldProtocol::encodeMessage(int address, int command, int value, char * output) {
	String message = "";
	message = message + address + ":" + command + ":" + value;
	message.toCharArray(output, 256);
	return 0;
}

int NerldProtocol::encodeMessage(int address, int command, String value, char * output) {
	String message = "";
	message = message + address + ":" + command + ":" + value;
	message.toCharArray(output, 256);
	return 0;
}

int NerldProtocol::encodeMessage(int address, int command, float value, char * output) {
	char floatBuffer[10];
	dtostrf(value, 5, 3, floatBuffer);

	String message = "";
	message = message + address + ":" + command + ":" + floatBuffer;
	message.toCharArray(output, 256);
	return 0;
}


