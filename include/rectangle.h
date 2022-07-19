#ifndef MPS_RECTANGLE_H_
#define MPS_RECTANGLE_H_

#include "vector2d.h"

/**
 * Rectangle with top-right corner at start, with width and height.
 */
struct Rectangle {
	/**
	 * Top-left corner of the rectangle.
	 */
	union {
		struct Vector2D _start;
		struct Vector2D;
	};

	/**
	 * Width of the rectangle.
	 */
	double width;

	/**
	 * Height of the rectangle.
	 */
	double height;
};

/**
 * Initialize rectangle with top left corner at (x, y).
 */
struct Rectangle *
rectangle_init(struct Rectangle *rect,
	       const double x, const double y,
	       const double width, const double height);

/**
 * Print rectangle to stdout.
 */
void
rectangle_print(const struct Rectangle *rect);

#endif /* MPS_RECTANGLE_H_ */
