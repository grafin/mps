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

void
circle_delete(void *obj)
{
	vector2d_delete(obj);
}

struct Circle *
circle_init(struct Circle *circle,
	    const double x, const double y, const double r)
{
	vector2d_init(&circle->_center, x, y);
	circle->type = CIRCLE;
	circle->print = _print;
	circle->delete = circle_delete;

	circle->r = r;

	return circle;
}

void
circle_print(const struct Circle *circle)
{
	mps_log(INFO, "Circle{%f, %f, %f}\n",
		circle->x, circle->y, circle->r);
}
