#include <stdio.h>
#include <stddef.h>

struct person_s {
	char *name;
	int age;
	int id;
	char *location;
};

int main(void)
{
	// using offset of to get the offset or memory layout
	printf("name: offset = %zu, sz = %zu\n", offsetof(struct person_s, name),
		sizeof(((struct person_s *)0)->name));
	printf("age: offset = %zu, sz = %zu\n", offsetof(struct person_s, age),
		sizeof(((struct person_s *)0)->age));
	printf("id: offset = %zu, sz = %zu\n", offsetof(struct person_s, id),
		sizeof(((struct person_s *)0)->id));
	printf("location: offset = %zu, sz = %zu\n", offsetof(struct person_s, location),
		sizeof(((struct person_s *)0)->location));

	return 0;
}
