#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "point2d.h"

typedef struct Rectangle {
	Point2D_t start;
	double width;
	double height;
} Rectangle_t;

void rectangle_print(const Rectangle_t*);

#endif /* RECTANGLE_H_ */
