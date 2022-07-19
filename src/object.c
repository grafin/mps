#include <log.h>
#include <object.h>

/**
 * Print object.
 */
static void
_print(const void *obj)
{
	mps_log(INFO,
		"Object of type %d\n", ((const struct Object *)obj)->type);
}

/**
 * Destructor for object.
 */
static void
_delete(void *obj)
{
	(void)obj;
}

struct Object *
object_init(void *obj)
{
	struct Object *o = (struct Object *)obj;
	o->type = UNKNOWN;
	o->print = _print;
	o->delete = _delete;

	return o;
}
