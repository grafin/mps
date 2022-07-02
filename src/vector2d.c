#include <vector2d.h>

#include <stdio.h>

void vector_print(const Vector2D_t *v)
{
	printf("Vector2D{%f, %f}\n", v->x, v->y);
}

/**
 * a = b + c
 */
Vector2D_t *vector2d_sum(Vector2D_t *a,
	const Vector2D_t *b, const Vector2D_t *c)
{
	a->x = b->x + c->x;
	a->y = b->y + c->y;

	return a;
}

/**
 * a = b - c
 */
Vector2D_t *vector2d_dif(Vector2D_t *a,
	const Vector2D_t *b, const Vector2D_t *c)
{
	a->x = b->x - c->x;
	a->y = b->y - c->y;

	return a;
}

/**
 * a = b * c
 */
Vector2D_t *vector2d_mul_float(Vector2D_t *a,
	const Vector2D_t *b, const float c)
{
	a->x = b->x * c;
	a->y = b->y * c;

	return a;
}
