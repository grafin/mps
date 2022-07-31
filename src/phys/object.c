#include <phys/object.h>

/**
 * Wrapper for phys_object_print function to use with Object.
 */
static void
_print(const void *obj)
{
	phys_object_print((const struct PhysObject *)obj);
}

void
phys_object_delete(void *obj)
{
	struct PhysObject *o = (struct PhysObject *)obj;
	vector2d_delete(&o->v);
	vector2d_delete(&o->a);

	object_delete(obj);
}

struct PhysObject *
phys_object_init(struct PhysObject *obj,
		 const double vx, const double vy)
{
	object_init(obj);

	obj->type = PHYS_OBJECT;
	obj->print = _print;
	obj->delete = phys_object_delete;

	vector2d_init(&obj->v, vx, vy);
	vector2d_init(&obj->a, 0, 0);

	return obj;
}

void
phys_object_print(const struct PhysObject *obj)
{
	mps_log(INFO, "PhysObject v{%f, %f}, a{%f, %f}",
		obj->v.x, obj->v.y, obj->a.x, obj->a.y);
}
