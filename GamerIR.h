#ifndef GamerIR_h
#define GamerIR_h

#include "Arduino.h"
#include "SoftwareSerial.h"

class GamerIR {
public:
	GamerIR();

	SoftwareSerial _serial;

	void send(char c);
	char receive();

private:
	char prevChar;
};

#endif
