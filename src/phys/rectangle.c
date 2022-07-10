#include <phys/rectangle.h>
#include <phys/universe.h>

void phys_rectangle_move(PhysRectangle_t *rect, double dt)
{
	Vector2D_t dx = {0};
	vector2d_mul_float(&dx, &rect->velocity, dt);
	vector2d_sum(&rect->start, &rect->start, &dx);

	if (rect->start.x + rect->width > universe.right_boundry &&
	    rect->velocity.x > 0)
		vector2d_flip_hor(&rect->velocity);

	if (rect->start.x < universe.left_boundary &&
	    rect->velocity.x < 0)
		vector2d_flip_hor(&rect->velocity);

	if (rect->start.y + rect->height > universe.bottom_boundary &&
	    rect->velocity.y > 0)
		vector2d_flip_ver(&rect->velocity);

	if (rect->start.y < universe.top_boundary &&
	    rect->velocity.y < 0)
		vector2d_flip_ver(&rect->velocity);
}
