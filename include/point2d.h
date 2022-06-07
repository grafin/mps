#ifndef POINT2D_H_
#define POINT2D_H_

typedef struct Point2D {
	double x, y;
} Point2D_t;

void point2d_print(const Point2D_t*);

#endif /* POINT2D_H_ */
