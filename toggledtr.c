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
		int DTR_flag;
		DTR_flag = TIOCM_DTR;                           /* Modem Constant for DTR pin */

        while(1) {
		    printf("DTR = 1\n");
		    ioctl(fd,TIOCMBIS,&DTR_flag);

/*            printf("Sleep 1s\n"); */
            sleep(1);

		    printf("DTR = 0\n");
		    ioctl(fd,TIOCMBIC,&DTR_flag);
        }
    }
}
