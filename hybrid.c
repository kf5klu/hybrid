#include <stdio.h>	   // Standard Input/Output header
#include <stdlib.h>    // Standard C Libraries
#include <unistd.h>    // UNIX standard function definitions
#include <fcntl.h>     // File control definitions
#include <errno.h>     // Error number definitions
#include <termios.h>   // UART stuff
#include "mpeters.h"   // Functions by Mike Peters
#include "jstreeter.h" // Functions by Jonathan Streeter

int main(void)
{

	double starts,Usecs;//For timing
	unsigned short adc_rcd=0;
	starts=0;
	Usecs=0;

	while(1)
	{
	//setup_array(accel, adc_rcd);					//Make ready to send
	printf("%0d\n",adc_rcd);							//Show me

	}
	return 0;
}
