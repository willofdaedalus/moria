#include <stdio.h>
#include <string.h>
#include <stdint.h>

// version one; naive approach with a byte copy
// works fine for most copy work
void *mem_cpy(void *dst, const void *src, size_t n)
{
	char *d = (char *)dst;
	const char *s = (char *)src;

	while (n--)
		*d++ = *s++;

	return dst;
}

// version two; came as a result of not being satisfied with
// version one. lots of research and confirmation with chatgpt
// the basic idea is to copy in chunks of size_t by checking
// that the two pointers "align" in memory i.e both are divisible
// by sizeof(size_t) in this case
// the reason for this check is to fall back to byte copying in the
// case where they don't align or use word-size copying in the case
// where they do align which takes less instructions (I need to look
// into this more) for the cpu to do the byte copying and moving
// than if they were misaligned
void *mem_cpy2(void *dst, const void *src, size_t n)
{
	char *d = (char *)dst;
	const char *s = (const char *)src;
	size_t sz = sizeof(size_t);

	// alignment checks are done here
	uintptr_t dst_aligned = (uintptr_t)d & (sz - 1);
	uintptr_t src_aligned = (uintptr_t)s & (sz - 1);
	int same_alignment = dst_aligned == src_aligned;

	// fall back to basic byte copying if they don't have same alignment
	if (!same_alignment || n < sz) {
		while (n--)
			*d++ = *s++;
	} else {
		// first, align both pointers to word boundaries
		while (((uintptr_t)d & (sz - 1)) != 0 && n > 0) {
			*d++ = *s++;
			n--;
		}

		// now both are word-aligned, safe to cast
		if (n >= sz) {
			size_t *wd = (size_t *)d;
			const size_t *ws = (const size_t *)s;
			size_t word_count = n / sz;

			// the actual word copying
			while (word_count--)
				*wd++ = *ws++;

			// update pointers for remaining bytes
			d = (char *)wd;
			s = (const char *)ws;
			n &= (sz - 1);  // remaining bytes
		}

		// copy remaining bytes
		while (n--)
			*d++ = *s++;
	}
	return dst;
}

int main(void)
{
	char *p = "the moria gauntlet";
	char dest[19] = {0};
	mem_cpy2(dest, p, 6);
	printf("%s\n", dest);
	return 0;
}
