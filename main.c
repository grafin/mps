#include "include/point2d.h"
#include "include/circle.h"

int main(int argc, char **argv)
{
	Point2D_t p = {1, 2};
	Circle_t c = {p, 10};

	point2d_print(p);
	circle_print(c);

	return 0;
}
