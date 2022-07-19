#include <log.h>
#include <circle.h>

void
circle_print(const struct Circle *circle)
{
	mps_log(INFO, "Circle{%f, %f, %f}\n",
		circle->center.x, circle->center.y, circle->radius);
}
