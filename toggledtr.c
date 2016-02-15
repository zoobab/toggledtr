#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>   	 /* File Control Definitions           */
#include <termios.h>	 /* POSIX Terminal Control Definitions */
#include <unistd.h> 	 /* UNIX Standard Definitions 	       */ 
#include <errno.h>   	 /* ERROR Number Definitions           */
#include <sys/ioctl.h>   /* ioctl()                            */

void main(void)
{
    int fd;                                             /* File Descriptor */
    fd = open("/dev/ttyUSB0",O_RDWR | O_NOCTTY );       /* ttyUSB0 is the USB2SERIAL Converter, O_RDWR is Read/Write access to serial port, O_NOCTTY is No terminal will control the process */
	if (fd == -1) {                                        /* Error Checking */
        printf("ttyUSB0 opening error, exiting\n");
        exit (1);
    }
    else {
        printf("ttyUSB0 opened successfully\n");
		printf("Controlling DTR pin\n");
		int DTR_flag;
		DTR_flag = TIOCM_DTR;                           /* Modem Constant for DTR pin */

        while(1) {
		    ioctl(fd,TIOCMBIS,&DTR_flag);
		    printf("DTR = 1\n");

            printf("Sleeping for 1 sec\n");
            sleep(2);

		    ioctl(fd,TIOCMBIC,&DTR_flag);
		    printf("DTR = 0\n");
        }
    }
}
