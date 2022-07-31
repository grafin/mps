#include <phys/rectangle.h>
#include <phys/universe.h>

/**
 * Wrapper for phys_rectangle_print function to use with Object.
 */
static void
_print(const void *obj)
{
	check_type(obj, PHYS_RECTANGLE);
	phys_rectangle_print((const struct PhysRectangle *)obj);
}

/**
 * Wrapper for phys_rectangle_move function to use with PhysObject.
 */
static void
_move(void *obj, const double dt)
{
	check_type(obj, PHYS_RECTANGLE);
	phys_rectangle_move((struct PhysRectangle *)obj, dt);
}

/**
 * Wrapper for phys_rectangle_collide function to use with PhysObject.
 */
static void
_collide(void *obj, const struct PhysObject *objects[])
{
	check_type(obj, PHYS_RECTANGLE);
	phys_rectangle_collide((struct PhysRectangle *)obj, objects);
}

/**
 * Destructor for physical rectangle.
 */
void
phys_rectangle_delete(void *obj)
{
	rectangle_delete(&((struct PhysRectangle *)obj)->rect);
	phys_object_delete(obj);
}

struct PhysRectangle *
phys_rectangle_init(struct PhysRectangle *rect,
		    const double x, const double y,
		    const double width, const double height,
		    const double vx, const double vy)
{
	phys_object_init(&rect->_phys_obj, vx, vy);
	rectangle_init(&rect->rect, x, y, width, height);

	rect->type = PHYS_RECTANGLE;
	rect->print = _print;
	rect->delete = phys_rectangle_delete;

	rect->move = _move;
	rect->collide = _collide;

	return rect;
}

void
phys_rectangle_move(struct PhysRectangle *rect, double dt)
{
	struct Vector2D dx;
	vector2d_init(&dx, 0, 0);
	vector2d_mul_float(&dx, &rect->v, dt);
	vector2d_sum(&rect->rect._start, &rect->rect._start, &dx);
	vector2d_delete(&dx);
}

void
phys_rectangle_collide(struct PhysRectangle *rect,
		       const struct PhysObject *objects[])
{
	if (rect->rect.x + rect->rect.width > universe.right_boundary &&
	    rect->v.x > 0)
		vector2d_flip_hor(&rect->v);

	if (rect->rect.x < universe.left_boundary &&
	    rect->v.x < 0)
		vector2d_flip_hor(&rect->v);

	if (rect->rect.y + rect->rect.height > universe.bottom_boundary &&
	    rect->v.y > 0)
		vector2d_flip_ver(&rect->v);

	if (rect->rect.y < universe.top_boundary &&
	    rect->v.y < 0)
		vector2d_flip_ver(&rect->v);

	for (int i = 0; objects[i]; i++) {
		if (objects[i] == (struct PhysObject *)rect)
			continue;
	}
}

void
phys_rectangle_print(const struct PhysRectangle *rect)
{
	mps_log(INFO, "PhysRectangle{%f, %f, %f, %f, %f, %f}\n",
		rect->rect.x, rect->rect.y,
		rect->rect.width, rect->rect.height,
		rect->v.x, rect->v.y);
}
