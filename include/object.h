#ifndef MPS_OBJECT_H_
#define MPS_OBJECT_H_

#include <log.h>

/**
 * Object types enumeration.
 */
enum ObjectType {
	UNKNOWN = 0,
	VECTOR2D,
	RECTANGLE,
	CIRCLE,
	CANVAS,
	COLOR,
	PHYS_UNIVERSE,
	PHYS_RECTANGLE,
};

struct Object {
	enum ObjectType type;
	void (*print)(const void *self);
	void (*delete)(void *self);
};

/**
 * Checks if obj is vector2d.
 */
static inline void
check_type(const struct Object *obj, enum ObjectType type)
{
	if (obj->type != type)
		mps_log(CRITICAL, "Wrong object type.");
}

#endif /* MPS_OBJECT_H_ */
