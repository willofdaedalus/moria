// Show the difference between little-endian and big-endian
#include <stdint.h>
#include <stdio.h>

int main(void)
{
	uint8_t buf[] = {0x12, 0x34, 0x56, 0x78};

	uint32_t little = buf[0] | buf[1]<<8 | buf[2]<<16 | buf[3]<<24;
	uint32_t big = buf[3] | buf[2]<<8 | buf[1]<<16 | buf[0]<<24;

	printf("little: %d\n", little);
	printf("big: %d\n", big);

	return 0;
}
