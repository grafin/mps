#include <phys/rectangle.h>

void phys_rectangle_move(PhysRectangle_t *rect, double dt)
{
	Vector2D_t dx = {0};
	vector2d_mul_float(&dx, &rect->velocity, dt);
	vector2d_sum(&rect->start, &rect->start, &dx);
}
