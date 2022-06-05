#include "../include/color.h"

#include <stdio.h>

void color_print(const Color_t *c)
{
	printf("Color{%d, %d, %d, %d}\n", c->r, c->g, c->b, c->a);
}
