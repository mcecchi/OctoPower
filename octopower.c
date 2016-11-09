#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "hidapi.h"

#define MAX_STR 255

int main(int argc, char* argv[])
{
	int retval;
	unsigned char buf[16];
	wchar_t wstr[MAX_STR];
	hid_device *handle;
	unsigned char socket;
	unsigned char bmap;

	if (argc != 3) {
		printf("Usage: %s <socket> <on|off>\n", argv[0]);
		return 0;
	}
	socket = *argv[1] - '0';
	if (socket > 1) {
		printf("Socket must be 0 or 1\n");
		return 0;
	}
	if (strncmp(argv[2], "on", 2) == 0) {
		bmap = 11;
	}
	else {
		bmap = 12;
	}
	// Open the device using the VID, PID,
	// and optionally the Serial number.
	handle = hid_open(0x04D8, 0x00DF, NULL);
	if (handle == NULL) {
		printf("Error opening device\n");
		return -1;
	}
	// Read the Manufacturer String
	retval = hid_get_manufacturer_string(handle, wstr, MAX_STR);
	if (retval == -1) {
		printf("Error calling hid_get_manifacturer_string\n");
		return retval;
	}
	printf("%ls", wstr);
	// Read the Product String
	retval = hid_get_product_string(handle, wstr, MAX_STR);
	if (retval == -1) {
		printf("Error calling hid_get_product_string\n");
		return retval;
	}
	printf(" %ls", wstr);
	// Read the Serial Number String
	retval = hid_get_serial_number_string(handle, wstr, MAX_STR);
	if (retval == -1) {
		printf("Error calling hid_get_serial_number_string\n");
		return retval;
	}
	printf(" S/N %ls\n", wstr);
	// Prepare buffer
	buf[0] = 0x08;	//SET_CLEAR_OUTPUTS
	buf[1] = 0x00;  // Don't care
	buf[2] = 0x00;  // Don't care
	buf[3] = 0x00;  // Don't care
	buf[4] = 0x00;  // Don't care
	buf[5] = 0x00;  // Don't care
	buf[6] = 0x00;  // Don't care
	buf[7] = 0x00;  // Don't care
	buf[8] = 0x00;  // Don't care
	buf[9] = 0x00;  // Don't care
	buf[10] = 0x00;  // Don't care
	buf[11] = 0x00; // Set_bmap
	buf[12] = 0x00; // Clear_bmap
	buf[13] = 0x00;  // Don't care
	buf[14] = 0x00;  // Don't care
	buf[15] = 0x00;  // Don't care
	buf[bmap] = 1 << socket;
	retval = hid_write(handle, buf, 16);
	if (retval == -1) {
		printf("Error calling hid_get_serial_number_string\n");
		return retval;
	}
	return 0;
}
