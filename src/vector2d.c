#include <log.h>
#include <vector2d.h>

#include <stdbool.h>
#include <math.h>

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
vector2d_copy(struct Vector2D *a, const struct Vector2D *b)
{
	a->x = b->x;
	a->y = b->y;

	return a;
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

/**
 * Return pointer to vector a whree projection of vector b on c is written.
 */
struct Vector2D *
vector2d_projection(struct Vector2D *a,
		    const struct Vector2D *b, const struct Vector2D *c)
{
	double t = vector2d_dot_product(b, c) / vector2d_len_square(c);
	vector2d_copy(a, c);
	return vector2d_mul_float(a, a, t);
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
vector2d_div_float(struct Vector2D *a,
		   const struct Vector2D *b, const float c)
{
	a->x = b->x / c;
	a->y = b->y / c;

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

struct Vector2D *
vector2d_norm(struct Vector2D *vector)
{
	return vector2d_div_float(vector, vector, vector2d_len(vector));
}

double
vector2d_dot_product(const struct Vector2D *a, const struct Vector2D *b)
{
	return a->x * b->x + a->y * b->y;
}

double
vector2d_len_square(const struct Vector2D *a)
{
	return vector2d_dot_product(a, a);
}

double
vector2d_len(const struct Vector2D *a)
{
	return sqrt(vector2d_len_square(a));
}
