#include <phys/circle.h>
#include <phys/universe.h>

/**
 * Wrapper for phys_circle_print function to use with Object.
 */
static void
_print(const void *obj)
{
	check_type(obj, PHYS_CIRCLE);
	phys_circle_print((const struct PhysCircle *)obj);
}

/**
 * Wrapper for phys_circle_move function to use with PhysObject.
 */
static void
_move(void *obj, const double dt)
{
	check_type(obj, PHYS_CIRCLE);
	phys_circle_move((struct PhysCircle *)obj, dt);
}

/**
 * Wrapper for phys_circle_collide function to use with PhysObject.
 */
static void
_collide(void *obj, const struct PhysObject *objects[])
{
	check_type(obj, PHYS_CIRCLE);
	phys_circle_collide((struct PhysCircle *)obj, objects);
}

/**
 * Destructor for physical circle.
 */
void
phys_circle_delete(void *obj)
{
	circle_delete(&((struct PhysCircle *)obj)->circle);
	phys_object_delete(obj);
}

struct PhysCircle *
phys_circle_init(struct PhysCircle *circle,
		 const double x, const double y, const double r,
		 const double vx, const double vy)
{
	phys_object_init(&circle->_phys_obj, vx, vy);
	circle_init(&circle->circle, x, y, r);

	circle->type = PHYS_CIRCLE;
	circle->print = _print;
	circle->delete = phys_circle_delete;

	circle->move = _move;
	circle->collide = _collide;

	return circle;
}

void
phys_circle_move(struct PhysCircle *circle, double dt)
{
	struct Vector2D dx;
	vector2d_init(&dx, 0, 0);
	vector2d_mul_float(&dx, &circle->v, dt);
	vector2d_sum(&circle->circle._center, &circle->circle._center, &dx);
	vector2d_delete(&dx);
}

void
phys_circle_collide(struct PhysCircle *circle,
		    const struct PhysObject *objects[])
{
	if (circle->circle.x + circle->circle.r > universe.right_boundary &&
	    circle->v.x > 0)
		vector2d_flip_hor(&circle->v);

	if (circle->circle.x - circle->circle.r < universe.left_boundary &&
	    circle->v.x < 0)
		vector2d_flip_hor(&circle->v);

	if (circle->circle.y + circle->circle.r > universe.bottom_boundary &&
	    circle->v.y > 0)
		vector2d_flip_ver(&circle->v);

	if (circle->circle.y - circle->circle.r < universe.top_boundary &&
	    circle->v.y < 0)
		vector2d_flip_ver(&circle->v);

	for (int i = 0; objects[i]; i++) {
		if (objects[i] == (struct PhysObject *)circle)
			continue;
		switch (objects[i]->type) {
		case PHYS_CIRCLE:
			{
				struct PhysCircle *obj =
					(struct PhysCircle *)objects[i];

				struct Vector2D distance;
				vector2d_init(&distance,
					      obj->circle.x - circle->circle.x,
					      obj->circle.y - circle->circle.y);

				double distance_len =
					vector2d_len_square(&distance);
				double min_distance_len = (
					(obj->circle.r + circle->circle.r) *
					(obj->circle.r + circle->circle.r));

				if (distance_len < min_distance_len) {
					vector2d_flip_ver(&circle->v);
					vector2d_flip_hor(&circle->v);
				}

				vector2d_delete(&distance);
				break;
			}
		default:
			break;
		}
	}
}

void
phys_circle_print(const struct PhysCircle *circle)
{
	mps_log(INFO, "PhysCircle{%f, %f, %f, %f, %f}\n",
		circle->circle.x, circle->circle.y, circle->circle.r,
		circle->v.x, circle->v.y);
}
