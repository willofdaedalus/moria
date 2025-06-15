#include <stdio.h>

#define SETTER(field) \
void set_##field(struct Point *p, int value) { p->field = value; }

#define ACCESSORS(field) \
void set_##field(struct Point *p, int v) \
{ p->field = v; } \
int get_##field(const struct Point *p) \
{ return p->field; }

#define ACCESSORS_FOR(type, field) \
void set_##field(type *t, int v) { t->field = v; } \
int get_##field(type *t) { return t->field; }

#define TYPED_ACCESSORS(type, field_type, field) \
void set_##field(type *t, field_type v) { t->field = v; } \
field_type get_##field(const type *t) { return t->field; }

#define MAKE_VAR(n) int var_##n

#define SAY_HELLO(name) printf("hello, " #name "!\n");

#define COLOURS \
	X(RED) \
	X(GREEN) \
	X(BLUE) \

struct Point {
	float x;
	int y;
};

TYPED_ACCESSORS(struct Point, float, x)
TYPED_ACCESSORS(struct Point, float, y)

int main(void)
{
	struct Point pt = {0, 0};
	set_x(&pt, 42.98123f);
	set_y(&pt, 56.3434f);

	SAY_HELLO(manny)

	printf("x = %f, y = %f\n", get_x(&pt), get_y(&pt));
}

