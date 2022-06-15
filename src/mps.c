#include <point2d.h>
#include <canvas.h>

#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#include <rectangle.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const float FPS = 60.0;

int main(void)
{
	bool running = true;
	SDL_Event e;

	double speed = 10;
	Color_t black = {0x00, 0x00, 0x00, 0xFF};
	Color_t white = {0xFF, 0xFF, 0xFF, 0xFF};
	Color_t red = {0xFF, 0x00, 0x00, 0xFF};

	Rectangle_t rect_1 = {{20, 20}, 100, 100};
	Rectangle_t rect_2 = {{50, 50}, 100, 100};

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

		canvas_draw_rectangle(canvas, &rect_2, &white);
		canvas_draw_rectangle(canvas, &rect_1, &red);

		rect_1.start.x = (int)(rect_1.start.x + speed) % SCREEN_WIDTH;
		rect_2.start.x = (int)(rect_2.start.x + 2*speed) % SCREEN_WIDTH;

		canvas_update(canvas);
		SDL_Delay(1000 / FPS);
	}

	canvas_delete(canvas);
	return 0;
}
