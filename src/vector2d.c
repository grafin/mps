#include <log.h>
#include <vector2d.h>

#include <stdio.h>
#include <stdbool.h>

/**
 * Wrapper for vector2d_print function to use with Object.
 */
static void
_print(const void *obj)
{
	check_type(obj, VECTOR2D);
	vector2d_print((const struct Vector2D *)obj);
}

/**
 * Destructor for vector2d.
 */
void
vector2d_delete(void *obj)
{
	object_delete(obj);
}

struct Vector2D *
vector2d_init(struct Vector2D *vector, const double x, const double y)
{
	object_init(vector);
	vector->type = VECTOR2D;
	vector->print = _print;
	vector->delete = vector2d_delete;

	vector->x = x;
	vector->y = y;

	return vector;
}

void
vector2d_print(const struct Vector2D *vector)
{
	mps_log(INFO, "Vector2D{%f, %f}\n", vector->x, vector->y);
}

struct Vector2D *
vector2d_sum(struct Vector2D *a,
	     const struct Vector2D *b, const struct Vector2D *c)
{
	a->x = b->x + c->x;
	a->y = b->y + c->y;

	return a;
}

struct Vector2D *
vector2d_dif(struct Vector2D *a,
	     const struct Vector2D *b, const struct Vector2D *c)
{
	a->x = b->x - c->x;
	a->y = b->y - c->y;

	return a;
}

struct Vector2D *
vector2d_mul_float(struct Vector2D *a,
		   const struct Vector2D *b, const float c)
{
	a->x = b->x * c;
	a->y = b->y * c;

	return a;
}

struct Vector2D *
vector2d_flip_hor(struct Vector2D *vector)
{
	vector->x *= -1;
	return vector;
}

struct Vector2D *
vector2d_flip_ver(struct Vector2D *vector)
{
	vector->y *= -1;
	return vector;
}
