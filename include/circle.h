#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "point2d.h"

typedef struct Circle {
	Point2D_t center;
	double radius;
} Circle_t;

void circle_print(const Circle_t c)
{
	printf("Circle{%f, %f, %f}\n", c.center.x, c.center.y, c.radius);
}

#endif /* CIRCLE_H_ */
