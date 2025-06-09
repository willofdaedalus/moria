// Declare a char, int, and pointer and print their sizes using sizeof
#include <stdio.h>

int main(void)
{
	int num = 42024;
	char ch = 'm';
	int *p = &num;

	printf("sizeof num is %d\n", (int)sizeof(num));
	printf("sizeof ch is %d\n", (int)sizeof(ch));
	printf("sizeof p is %d\n", (int)sizeof(*p));

	return 0;
}
