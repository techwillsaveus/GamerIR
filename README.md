# DIY Gamer Kit Infrared Library

This is an additional library for the [DIY Gamer Kit](https://www.techwillsaveus.com/shop/diy-kits/diy-gamer-kit-arduino/). It enables multiplayer game creation and communication over the infrared transmitter and receiver. 

## Installation

1. Install **Arduino**. You can get the software [here](http://www.arduino.cc/download).
2. Download the latest **release** from the **releases** page on this repository.
3. Unzip the library.
4. Put the `Gamer` folder inside the Arduino libraries folder. The location of this folder will depend on your operating system. 

Operating system | Folder
---------------- | --------------------------------
Windows          | `My Documents\Arduino\libraries`
Mac OS X         | `Documents/Arduino/libraries`
Linux            | `~/Documents/Arduino/libraries`

The exact folder on your computer may be a little different. That's OK.

**Almost there!**

## Testing your installation

1. Open or restart the Arduino program (if it was already open)
2. Go to **File** → **Examples** → **GamerIR** and choose one of the example programs. `IRExample` is a great place to start.
3. Click on the **Verify** button to compile the example (the tick on the top left of the Arduino environment).

If the library hasn't been put in the right folder, you will get red errors saying something like `Symbol not found`. Make sure you have unzipped the library correctly and put it in the right folder.