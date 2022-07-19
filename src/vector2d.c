#include <log.h>
#include <vector2d.h>

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
