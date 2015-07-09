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
void GamerIR::send(String message)
{
  String mes = message;
	_serial.write(mes.length());
  for(int i=0; i<mes.length(); i++) {
    _serial.write(mes.charAt(i));
    _serial.write(~mes.charAt(i));
  }
	// End byte
	_serial.write(0x3);
}

/**
  Returns a string received from the IR receiver.
  @return the string received by the IR receiver
 */
String GamerIR::receive(){
  char ch;
  String message;
  char messageLength;
	bool lengthReceived;
	char cch,incch;

	if(_serial.available() > 0) {
		messageLength = _serial.read();
		
		for(int i=0; i<messageLength; i++) {
			ch = _serial.read();
			if(ch == 0x3); // fucked.
			else {
				if(ch == ~prevChar) message = message + prevChar;
				prevChar = ch;
			}
		}

		if(_serial.read() == 0x3) return message;
		else return "ERROR";
	}
/*
  int n, i;
  n = _serial.available();

  i = n;

  while(i--){
    ch = _serial.read();
    if(ch == ~prevChar) message = message+prevChar;
    prevChar = ch;

  }

  return message;
*/

}
