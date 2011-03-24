#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/parport.h>
#include <linux/ppdev.h>


int main(int argc,char* argv[])
{
	int device_handle;
	unsigned char output;

	device_handle = open("/dev/parport0",O_WRONLY);
	if(device_handle < 0) {
		printf("Cannot open /dev/parport0\n");
		return 0;
	}

	if(argv[1][0]=='1')
		output=0xFF;
	else
		output=0x00;
	ioctl(device_handle,PPWDATA,&output);
	printf("output %x\n",output);

	close(device_handle);

	return 0;
}
