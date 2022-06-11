#include <point2d.h>

#include <stdio.h>

void point2d_print(const Point2D_t *p)
{
	printf("Point2D{%f, %f}\n", p->x, p->y);
}
