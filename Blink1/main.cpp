//------------------------------------------------------------------------------
// Author:	Nathan Wiley	
// File:	main.cpp
// Date:	12/12/2022
// Desc:	Template for Raspberry Pi projects and code documentation
//------------------------------------------------------------------------------

#include <iostream>
#include <thread>
#include <chrono>
#include <pigpio.h>

using namespace std;

#define	LED	26
#define _DELAY 2000

int main(void)
{
	//Initialise GPIO
	gpioInitialise();

	//Set up GPIO for LED
	gpioSetMode(LED, PI_OUTPUT);

	//Blink loop
	while (true)
	{
		cout << "Hello! - code from my pc" << endl;

		//Turns on LED pin then delays
		gpioWrite(LED, PI_HIGH);
		std::this_thread::sleep_for(std::chrono::milliseconds(_DELAY));

		//Turns off LED pin then delays
		gpioWrite(LED, PI_LOW);
		std::this_thread::sleep_for(std::chrono::milliseconds(_DELAY));

	}

	//Terminates GPIO instance
	gpioTerminate();

	return 0;
}