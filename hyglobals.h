/*
 * hyglobals.h
 *
 *  Created on: Jul 22, 2011
 *     Authors: Mike Peters and Jonathan Streeter
 */

#ifndef HYGLOBALS_H_
#define HYGLOBALS_H_

//#include	<termios.h>
//Define universal data types
typedef unsigned char   u8b;  //8-bit typedef
typedef unsigned short  u16b; //16-bit typedef
typedef unsigned int    u32b; //32-bit typedef
typedef unsigned long   u64b; //64-bit typedef

//Define constant variables

#ifndef Points_To_Port
#define Points_To_Port
int mainfp=0;
#endif
//Functions

//Transmit UART to PIC
void TX(u8b data_out[])
{
	int open_port(void);//Declares it
		if (mainfp==0){	mainfp=open_port();	}//Checks if the port is open Else opens it
			//open_port();}	// call the one to setup serial
		write(mainfp, data_out, data_out[0]);//Pointer to the serial line,Data array,Bytes to be sent
		return;//Done
}


int open_port(void)
 {
   	int fd;                                   /* File descriptor for the port */
       struct termios options;

   	fd = open("/dev/ttyS0", O_RDWR | O_NOCTTY | O_NDELAY);

   	if (fd == -1)
   	{                                              /* Could not open the port */
    	fprintf(stderr, "open_port: Unable to open /dev/ttyS0 :(\n");
   	}

 	fcntl(fd, F_SETFL, FNDELAY);                  /* Configure port reading */
                                     /* Get the current options for the port */
 	tcgetattr(fd, &options);
 	cfsetispeed(&options, B19200);                 /* Set the baud rates to 19200 */
 	cfsetospeed(&options, B19200);
//
//                                   /* Enable the receiver and set local mode */
// 	//options.c_cflag |= (CLOCAL | CREAD);
// 	options.c_cflag |= CRTSCTS | CS8 | CLOCAL | CREAD;

 	options.c_cflag &= ~PARENB; /* Mask the character size to 8 bits, no parity */
 	options.c_cflag &= ~CSTOPB;
 	options.c_cflag &= ~CSIZE;
 	options.c_cflag |=  CS8;                              /* Select 8 data bits */
 	options.c_cflag &= ~CRTSCTS;               /* Disable hardware flow control */
 //	options.c_oflag = 0;
 	options.c_oflag &= ~OPOST;
//                                 /* Enable data to be processed as raw input */
 	options.c_lflag &= ~(ICANON | ECHO | ISIG);
// //	options.c_lflag &= ~(ICANON | ECHO | ISIG);
// 	options.c_lflag = ICANON;
// 	/* Set the new options for the port */


 	tcflush(fd, TCIFLUSH);
 	tcsetattr(fd, TCSANOW, &options);
   	return (fd);
 }
#endif /* HYGLOBALS_H_ */
