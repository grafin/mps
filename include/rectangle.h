#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "vector2d.h"

/**
 * Rectangle with top-right corner at start, with width and height.
 */
struct Rectangle {
	/**
	 * Top-left corner of the rectangle.
	 */
	struct Vector2D start;

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
 * Print rectangle to stdout.
 */
void
rectangle_print(const struct Rectangle *rect);

#endif /* RECTANGLE_H_ */
