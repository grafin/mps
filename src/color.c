#include <log.h>
#include <color.h>

void
color_print(const struct Color *color)
{
	mps_log(INFO, "Color{%d, %d, %d, %d}\n",
		color->r, color->g, color->b, color->a);
}
