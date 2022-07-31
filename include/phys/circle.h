#ifndef MPS_PHYS_CIRCLE_H_
#define MPS_PHYS_CIRCLE_H_

#include <phys/object.h>
#include <circle.h>

/**
 * Physical model of circle.
 */
struct PhysCircle {
	union {
		/**
		 * Physical object.
		 */
		struct PhysObject _phys_obj;
		struct PhysObject;
	};

	/**
	 * Corresponding circle.
	 */
	struct Circle circle;
};

/**
 * Initialize physical circle.
 */
struct PhysCircle *
phys_circle_init(struct PhysCircle *circle,
		    const double x, const double y, const double r,
		    const double vx, const double vy);

/**
 * Destructor for physical circle.
 */
void
phys_circle_delete(void *obj);

/**
 * Print physical circle to stdout.
 */
void
phys_circle_print(const struct PhysCircle *circle);

/**
 * Change circle position in space, after dt time passes.
 */
void
phys_circle_move(struct PhysCircle *circle, double dt);

/**
 * Process collisions for circle with objects.
 */
void
phys_circle_collide(struct PhysCircle *circle,
		    const struct PhysObject *objects[]);
#endif /* MPS_PHYS_CIRCLE_H_ */
