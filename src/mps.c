#include <point2d.h>
#include <canvas.h>

#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const float FPS = 30.0;

int draw_vertical_line(
	Canvas_t *canvas, const Point2D_t *start, const Color_t *color)
{
	Point2D_t point = *start;

	for (int i = 0; i < 100; i++) {
		if (canvas_draw_point2d(canvas, &point, color) != 0) {
			canvas_delete(canvas);
			return -1;
		}

		point.y++;
	}

	return 0;
}

int main(void)
{
	bool running = true;
	SDL_Event e;

	double speed = 10;
	Point2D_t point = {20, 100};
	Color_t black = {0x00, 0x00, 0x00, 0xFF};
	//Color_t white = {0xFF, 0xFF, 0xFF, 0xFF};
	Color_t red = {0xFF, 0x00, 0x00, 0xFF};

	Canvas_t *canvas = canvas_create(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (canvas == NULL)
		return -1;

	while (running) {
		while(SDL_PollEvent(&e) != 0) {
			if(e.type == SDL_QUIT)
				running = false;
		}

		if (canvas_fill(canvas, &black) != 0) {
			canvas_delete(canvas);
			return -1;
		}

		draw_vertical_line(canvas, &point, &red);
		point.x = (unsigned)(point.x + speed) % SCREEN_WIDTH;

		canvas_update(canvas);
		SDL_Delay(1000 / FPS);
	}

	canvas_delete(canvas);
	return 0;
}
