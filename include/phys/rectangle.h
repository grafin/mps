#ifndef PHYS_RECTANGLE_H_
#define PHYS_RECTANGLE_H_

#include <rectangle.h>

typedef struct PhysRectangle {
	union {
		struct Rectangle _rect;
		struct {
			struct Vector2D start;
			double width;
			double height;
		};
	};
	struct Vector2D velocity;
} PhysRectangle_t;

void phys_rectangle_move(PhysRectangle_t *rect, double dt);

#endif /* PHYS_RECTANGLE_H_ */
