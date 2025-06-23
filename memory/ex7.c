#include <stdio.h>
#include <stdint.h>

#define BYTESZ (8)
enum endian_type {LITTLE, BIG};

enum endian_type check_endianess()
{
	enum endian_type type = LITTLE;
	uint8_t x = 0x1;
	uint8_t *ptr = (uint8_t*)&x;

	if (*ptr == 0x1)
		return LITTLE;

	return BIG;
}

int _swap_endianess(int value, enum endian_type source_type)
{
	// determine machine endianness
	int test = 0x1;
	int is_little_endian = *(char*)&test == 0x1;

	// if source matches native, no conversion needed
	if ((source_type == LITTLE && is_little_endian) || 
		(source_type == BIG && !is_little_endian)) {
		return value;
	}

	// otherwise, swap bytes
	char *chunks = (char*)&value;
	int final = 0;
	int byte_sz = 0;

	for (int i = 0; i < sizeof(int); i++)
		final |= ((unsigned char)chunks[i]) << ((sizeof(int) - 1 - i) * 8);

	return final;
}

int swap_endianess(int num, enum endian_type source_type)
{
	int swapped = ((num>>24)&0xff) | // move byte 3 to byte 0
		((num<<8)&0xff0000) | // move byte 1 to byte 2
		((num>>8)&0xff00) | // move byte 2 to byte 1
		((num<<24)&0xff000000); // byte 0 to byte 3

	return swapped;
}

int main(void)
{
	int k = 0x1234567;
	printf("k before swap %d\n", k);
	k = _swap_endianess(k, BIG);
	printf("k after swap %d\n", k);
	k = _swap_endianess(k, LITTLE);
	printf("k after swap %d to little\n", k);

	return 0;
}
