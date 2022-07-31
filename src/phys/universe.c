#include <phys/universe.h>

struct Universe universe;

void
universe_init(double left_boundary, double right_boundary,
	      double top_boundary, double bottom_boundary)
{
	universe.left_boundary = left_boundary;
	universe.right_boundary = right_boundary;
	universe.top_boundary = top_boundary;
	universe.bottom_boundary = bottom_boundary;
}
