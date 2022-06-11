#include <point2d.h>
#include <canvas.h>

#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	Point2D_t point = {20, 100};
	Color_t black = {0x00, 0x00, 0x00, 0xFF};
	Color_t white = {0xFF, 0xFF, 0xFF, 0xFF};
	Color_t red = {0xFF, 0x00, 0x00, 0xFF};

	Canvas_t *canvas = canvas_create(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (canvas == NULL)
		return -1;

	if (canvas_fill(canvas, &black) != 0) {
		canvas_delete(canvas);
		return -1;
	}

	for (int i = 0; i < 100; i++) {
		if (canvas_draw_point2d(canvas, &point, &red) != 0) {
			canvas_delete(canvas);
			return -1;
		}

		point.y++;
	}
	canvas_update(canvas);

	canvas_delete(canvas);
	return 0;
}
