#include <circle.h>

#include <stdio.h>

void
circle_print(const struct Circle *circle)
{
	printf("Circle{%f, %f, %f}\n",
	       circle->center.x, circle->center.y, circle->radius);
}
