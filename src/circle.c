#include "../include/circle.h"

#include <stdio.h>

void circle_print(const Circle_t c)
{
	printf("Circle{%f, %f, %f}\n", c.center.x, c.center.y, c.radius);
}