#include <rectangle.h>

#include <stdio.h>

void
rectangle_print(const struct Rectangle *rect)
{
	printf("Rectangle{%f, %f, %f, %f}\n",
	       rect->start.x, rect->start.y, rect->width, rect->height);
}
