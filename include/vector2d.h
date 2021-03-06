#ifndef MPS_VECTOR_2D_H_
#define MPS_VECTOR_2D_H_

#include <object.h>

/**
 * Two-dimentional vector.
 */
struct Vector2D {
	/**
	 * Inherit Object.
	 */
	union {
		struct Object _obj;
		struct Object;
	};

	/**
	 * Coordinates of the vector.
	 */
	double x, y;
};

/**
 * Initialize vector at point (x, y).
 */
struct Vector2D *
vector2d_init(struct Vector2D *vector, const double x, const double y);

/**
 * Destructor for vector2d.
 */
void
vector2d_delete(void *obj);

/**
 * Print vector to stdout.
 */
void
vector2d_print(const struct Vector2D *vector);

/**
 * Returns pointer to vector a = b + c.
 */
struct Vector2D *
vector2d_sum(struct Vector2D *a,
	     const struct Vector2D *b, const struct Vector2D *c);

/**
 * Returns pointer to vector a = b - c.
 */
struct Vector2D *
vector2d_dif(struct Vector2D *a,
	     const struct Vector2D *b, const struct Vector2D *c);

/**
 * Returns pointer to vector a = b * c.
 */
struct Vector2D *
vector2d_mul_float(struct Vector2D *a,
		   const struct Vector2D *b, const float c);

/**
 * Flips vector horizontally and returns pointer to it.
 */
struct Vector2D *
vector2d_flip_hor(struct Vector2D *vector);

/**
 * Flips vector vertically and returns pointer to it.
 */
struct Vector2D *
vector2d_flip_ver(struct Vector2D *vector);

#endif /* MPS_VECTOR_2D_H_ */
