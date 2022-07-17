#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "vector2d.h"

/**
 * Circle with center and radius.
 */
struct Circle {
	/**
	 * Center of the circle.
	 */
	struct Vector2D center;

	/**
	 * Radius of the circle.
	 */
	double radius;
};

/**
 * Print circle to stdout.
 */
void
circle_print(const struct Circle *circle);

#endif /* CIRCLE_H_ */
