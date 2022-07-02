#include <phys/rectangle.h>

void phys_rectangle_move(PhysRectangle_t *rect, double dt)
{
	rect->start.x += rect->velocity.x * dt;
	rect->start.y += rect->velocity.y * dt;
}
