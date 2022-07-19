#include <log.h>
#include <circle.h>

/**
 * Wrapper for circle_print function to use with Object.
 */
static void
_print(const void *obj)
{
	check_type(obj, CIRCLE);
	circle_print((const struct Circle *)obj);
}

/**
 * Destructor for circle.
 */
static void
_delete(void *obj)
{
	check_type(obj, CIRCLE);
	struct Circle *circle = (struct Circle *)obj;
	circle->_center.delete(&circle->_center);
}

struct Circle *
circle_init(struct Circle *circle,
	    const double x, const double y, const double r)
{
	circle->type = CIRCLE;
	circle->print = _print;
	circle->delete = _delete;

	vector2d_init(&circle->_center, x, y);
	circle->r = r;

	return circle;
}

void
circle_print(const struct Circle *circle)
{
	mps_log(INFO, "Circle{%f, %f, %f}\n",
		circle->x, circle->y, circle->r);
}
