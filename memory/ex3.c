#include <stdio.h>

struct child_s {
	short a;
	int b;
	char c;
};

struct kid_s {
	int a;
	short b;
	char c;
};
// the two structs below look similar, but their layout in memory is quite different
// one uses ~33% more memory than the other because of alignment rules
//
// compilers typically align members to the size of their largest type to match the
// word size of the processor. to do this, they add invisible "padding" bytes (also
// called slop) between or after members
//
// the general rule: each field must start at an offset that's a multiple of its alignment
// requirement (usually its size). the compiler may insert padding to enforce that
//
// in struct child_s (short-int-char):
//   short a;   // 2 bytes
//   padding    // 2 bytes (to align next int)
//   int   b;   // 4 bytes
//   char  c;   // 1 byte
//   padding    // 3 bytes (to make total size a multiple of 4)
//   => total size: 12 bytes
//
// in struct kid_s (int-short-char):
//   int   a;   // 4 bytes
//   short b;   // 2 bytes
//   char  c;   // 1 byte
//   padding    // 1 byte
//   => total size: 8 bytes
//
// so by reordering members to pack smaller fields after bigger ones, we save 4 bytes here.
// again though this is all dependent of many other factors like compile flags and even
// architecture

int main(void)
{
	printf("sizeof child_s is %d\n", (int)sizeof(struct child_s));
	printf("sizeof kid_s is %d\n", (int)sizeof(struct kid_s));
	return 0;
}
