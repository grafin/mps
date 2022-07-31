#ifndef MPS_PHYS_RECTANGLE_H_
#define MPS_PHYS_RECTANGLE_H_

#include <phys/object.h>
#include <rectangle.h>

/**
 * Physical model of rectangle.
 */
struct PhysRectangle {
	union {
		/**
		 * Physical object.
		 */
		struct PhysObject _phys_obj;
		struct PhysObject;
	};

	/**
	 * Corresponding rectangle.
	 */
	struct Rectangle rect;
};

/**
 * Initialize physical rectangle.
 */
struct PhysRectangle *
phys_rectangle_init(struct PhysRectangle *rect,
		    const double x, const double y,
		    const double width, const double height,
		    const double vx, const double vy);

/**
 * Destructor for physical rectangle.
 */
void
phys_rectangle_delete(void *obj);

/**
 * Print physical rectangle to stdout.
 */
void
phys_rectangle_print(const struct PhysRectangle *rect);

/**
 * Change rectangle position in space, after dt time passes.
 */
void
phys_rectangle_move(struct PhysRectangle *rect, double dt);

/**
 * Process collisions for rectanlge with objects.
 */
void
phys_rectangle_collide(struct PhysRectangle *rect,
		       const struct PhysObject *objects[]);
#endif /* MPS_PHYS_RECTANGLE_H_ */
