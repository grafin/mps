#ifndef MPS_OBJECT_H_
#define MPS_OBJECT_H_

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
	void (*print)(const struct Object *self);
	void (*delete)(struct Object *self);
};

#endif /* MPS_OBJECT_H_ */
