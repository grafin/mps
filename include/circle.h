#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "point2d.h"

typedef struct Circle {
	Point2D_t center;
	double radius;
} Circle_t;

void circle_print(const Circle_t*);

#endif /* CIRCLE_H_ */
