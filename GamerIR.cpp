#include "GamerIR.h"

/**
	Constructor. Also initiates software serial.
	*/
GamerIR::GamerIR() : _serial(5, 4) {
	_serial.begin(2400);
}

/**
  Sends a string through the IR transmitter.
  @param message the char that will be transmitted
 */
void GamerIR::send(char c)
{
	// Send character.
	_serial.write(c);
	// Send logical inverse of the character.
	_serial.write(~c);
}

/**
  Returns a character received from the IR receiver.
  @return the char received by the IR receiver
 */
char GamerIR::receive(){
	char incomingChar;
  int i = _serial.available();
	char charReceived;
	
	// Cycle through all incoming data, and decide if it's genuine.
  while(i--){
    incomingChar = _serial.read();
    if(incomingChar == ~prevChar) charReceived = prevChar;
    prevChar = incomingChar;

  }

	// Return the character received.
  return charReceived;
}
