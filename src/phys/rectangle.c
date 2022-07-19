#include <phys/rectangle.h>
#include <phys/universe.h>

void
phys_rectangle_move(struct PhysRectangle *rect, double dt)
{
	struct Vector2D dx;
	vector2d_init(&dx, 0, 0);
	vector2d_mul_float(&dx, &rect->velocity, dt);
	vector2d_sum(&rect->_start, &rect->_start, &dx);

	if (rect->x + rect->width > universe.right_boundry &&
	    rect->velocity.x > 0)
		vector2d_flip_hor(&rect->velocity);

	if (rect->x < universe.left_boundary &&
	    rect->velocity.x < 0)
		vector2d_flip_hor(&rect->velocity);

	if (rect->y + rect->height > universe.bottom_boundary &&
	    rect->velocity.y > 0)
		vector2d_flip_ver(&rect->velocity);

	if (rect->y < universe.top_boundary &&
	    rect->velocity.y < 0)
		vector2d_flip_ver(&rect->velocity);
}
