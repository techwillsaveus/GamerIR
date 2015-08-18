#include "GamerIR.h"

/**
	Constructor. Also initiates software serial.
	*/
GamerIR::GamerIR() : _serial(5, 4) {
	_serial.begin(2400);
}
/**
  Sends a string through the IR transmitter.
  @param message the string that will be transmitted
 */
void GamerIR::send(char message)
{
	char mes = message;
    _serial.write(mes);
    _serial.write(~mes);
}

/**
  Returns a string received from the IR receiver.
  @return the string received by the IR receiver
 */
char GamerIR::receive(){
	char ch;
	char message;

	int i = _serial.available();

	while(i--){
    	ch = _serial.read();
    	if(ch == ~prevChar) message = prevChar;
    	prevChar = ch;
	}

	return message;
}
