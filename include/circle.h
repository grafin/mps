#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "vector2d.h"

typedef struct Circle {
	Vector2D_t center;
	double radius;
} Circle_t;

void circle_print(const Circle_t*);

#endif /* CIRCLE_H_ */
