#ifndef MPS_CIRCLE_H_
#define MPS_CIRCLE_H_

#include "vector2d.h"

/**
 * Circle with center and radius.
 */
struct Circle {
	/**
	 * Center of the circle.
	 */
	union {
		struct Vector2D _center;
		struct Vector2D;
	};

	/**
	 * Radius of the circle.
	 */
	double r;
};

/**
 * Initialize circle with center at (x, y) and radius r.
 */
struct Circle *
circle_init(struct Circle *circle,
	    const double x, const double y, const double r);

/**
 * Print circle to stdout.
 */
void
circle_print(const struct Circle *circle);

#endif /* MPS_CIRCLE_H_ */
