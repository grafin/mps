#ifndef PHYS_RECTANGLE_H_
#define PHYS_RECTANGLE_H_

#include <rectangle.h>

/**
 * Physical model of rectangle.
 */
struct PhysRectangle {
	union {
		struct Rectangle;

		/**
		 * Rectangle object.
		 */
		struct Rectangle _rect;
	};

	/**
	 * Current velocity vector.
	 */
	struct Vector2D velocity;
};

/**
 * Change rectangle position in space, after dt time passes.
 */
void
phys_rectangle_move(struct PhysRectangle *rect, double dt);

#endif /* PHYS_RECTANGLE_H_ */
