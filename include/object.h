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

	UNIVERSE,

	PHYS_OBJECT,
	PHYS_RECTANGLE,
	PHYS_CIRCLE,
};

struct Object {
	enum ObjectType type;
	void (*print)(const void *self);
	void (*delete)(void *self);
};

/**
 * Initialize object.
 */
struct Object *
object_init(void *obj);

/**
 * Destructor for object.
 */
void
object_delete(void *obj);

/**
 * Checks objects type.
 */
static inline void
check_type(const struct Object *obj, enum ObjectType type)
{
	if (obj->type != type)
		mps_log(CRITICAL, "Wrong object type.");
}

#endif /* MPS_OBJECT_H_ */
