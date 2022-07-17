#include <color.h>

#include <stdio.h>

void
color_print(const struct Color *color)
{
	printf("Color{%d, %d, %d, %d}\n",
	       color->r, color->g, color->b, color->a);
}
