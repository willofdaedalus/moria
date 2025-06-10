// Write a function that manually sets bytes in an int using char*
#include <stdio.h>

int pack_bytes(char *target)
{
	int value = 0;
	int i = 0, sz = (int)sizeof(int);
	char *p = (char*)&value;

	while (target && i < sz) {
		*p++ = *target++;
		i++;
	}

	return value;
}

void unpack_bytes(int value, char *out)
{
	int sz = (int)sizeof(value);
	char *v = (char *)&value;
	for (int i = 0; i < sz; i++)
		out[i] = v[i];

	out[sz] = '\0';
}

int main(void)
{
	int value = pack_bytes("dude");
	printf("dude packed is %d\n", value);

	char out[5] = {0};
	unpack_bytes(value, out);
	printf("%d is %s unpacked\n", value, out);

	return 0;
}
