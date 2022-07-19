#include <log.h>
#include <rectangle.h>

/**
 * Wrapper for rectangle_print function to use with Object.
 */
static void
_print(const void *obj)
{
	check_type(obj, RECTANGLE);
	rectangle_print((const struct Rectangle *)obj);
}

void
rectangle_delete(void *obj)
{
	vector2d_delete(obj);
}

struct Rectangle *
rectangle_init(struct Rectangle *rect,
	       const double x, const double y,
	       const double width, const double height)
{
	vector2d_init(&rect->_start, x, y);
	rect->type = RECTANGLE;
	rect->print = _print;
	rect->delete = rectangle_delete;

	rect->width = width;
	rect->height = height;

	return rect;
}

void
rectangle_print(const struct Rectangle *rect)
{
	mps_log(INFO, "Rectangle{%f, %f, %f, %f}\n",
		rect->x, rect->y, rect->width, rect->height);
}
