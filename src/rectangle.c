#include <rectangle.h>

#include <stdio.h>

void rectangle_print(const Rectangle_t *r)
{
	printf("Rectangle{%f, %f, %f, %f}\n",
		r->start.x, r->start.y, r->width, r->height);
}
