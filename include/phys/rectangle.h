#ifndef PHYS_RECTANGLE_H_
#define PHYS_RECTANGLE_H_

#include <rectangle.h>

typedef struct PhysRectangle {
	union {
		Rectangle_t _rect;
		struct {
			Vector2D_t start;
			double width;
			double height;
		};
	};
	Vector2D_t velocity;
} PhysRectangle_t;

void phys_rectangle_move(PhysRectangle_t *rect, double dt);

#endif /* PHYS_RECTANGLE_H_ */
