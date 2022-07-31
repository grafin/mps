#ifndef MPS_PHYS_OBJECT_H_
#define MPS_PHYS_OBJECT_H_

#include <object.h>
#include <vector2d.h>

struct PhysObject {
	/**
	 * Parent object.
	 */
	union {
		struct Object _obj;
		struct Object;
	};

	/**
	 * Velocity vector.
	 */
	struct Vector2D v;

	/**
	 * Acceleration vector.
	 */
	struct Vector2D a;

	void (*move)(void *self, const double dt);
	void (*collide)(void *self, const struct PhysObject *objects[]);
};

/**
 * Initialize physical object.
 */
struct PhysObject *
phys_object_init(struct PhysObject *obj,
		 const double vx, const double vy);

/**
 * Destructor for object.
 */
void
phys_object_delete(void *obj);

/**
 * Print physical object to stdout.
 */
void
phys_object_print(const struct PhysObject *obj);

#endif /* MPS_PHYS_OBJECT_H_ */
