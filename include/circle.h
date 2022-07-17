#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "vector2d.h"

typedef struct Circle {
	struct Vector2D center;
	double radius;
} Circle_t;

void circle_print(const Circle_t*);

#endif /* CIRCLE_H_ */
