#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "vector2d.h"

typedef struct Rectangle {
	struct Vector2D start;
	double width;
	double height;
} Rectangle_t;

void rectangle_print(const Rectangle_t*);

#endif /* RECTANGLE_H_ */
