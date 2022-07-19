#include <log.h>
#include <rectangle.h>

void
rectangle_print(const struct Rectangle *rect)
{
	mps_log(INFO, "Rectangle{%f, %f, %f, %f}\n",
		rect->start.x, rect->start.y, rect->width, rect->height);
}
