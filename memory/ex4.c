#include <stdio.h>
#include <string.h>
#include <stdint.h>

void *mem_cpy(void *dst, const void *src, size_t n)
{
	char *d = (char *)dst;
	const char *s = (char *)src;

	while (n--)
		*d++ = *s++;

	return dst;
}

void *mem_cpy2(void *dst, const void *src, size_t n)
{
	char *d = (char *)dst;
	const char *s = (char *)src;
	int sz = sizeof(size_t) - 1;
	int aligned = (((uintptr_t)d & sz) == 0) ==
		(((uintptr_t)s & sz) == 0);


}

int main(void)
{
	char *p = "the moria gauntlet";
	char dest[19] = {0};
	mem_cpy(dest, p, strlen(p));
	printf("%s\n", dest);
	return 0;
}
