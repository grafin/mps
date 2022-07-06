#include <canvas.h>

#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#include <rectangle.h>

#include <vector2d.h>
#include <phys/rectangle.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int TITLE_LEN = 255;

const float FPS = 60.0;

int main(void)
{
	bool running = true;
	char title[TITLE_LEN + 1];
	SDL_Event e;

	Color_t black = {0x00, 0x00, 0x00, 0xFF};
	Color_t red = {0xFF, 0x00, 0x00, 0xFF};
	Rectangle_t start = {{0, 100}, 100, 100};

	PhysRectangle_t rect_1 = {{start}, {400, 100}};

	Canvas_t *canvas = canvas_create(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (canvas == NULL)
		return -1;

	double dt = 0;
	uint64_t frame = 0;
	while (running) {
		uint64_t t_0 = SDL_GetTicks64();

		while(SDL_PollEvent(&e) != 0) {
			if(e.type == SDL_QUIT)
				running = false;
		}

		if (canvas_fill(canvas, &black) != 0) {
			canvas_delete(canvas);
			return -1;
		}

		phys_rectangle_move(&rect_1, dt);

		if (rect_1.start.x + rect_1.width > SCREEN_WIDTH &&
		    rect_1.velocity.x > 0)
			rect_1.velocity.x *= -1;

		if (rect_1.start.x < 0 &&
		    rect_1.velocity.x < 0)
			rect_1.velocity.x *= -1;

		if (rect_1.start.y + rect_1.height > SCREEN_HEIGHT &&
		    rect_1.velocity.y > 0)
			rect_1.velocity.y *= -1;

		if (rect_1.start.y < 0 &&
		    rect_1.velocity.y < 0)
			rect_1.velocity.y *= -1;

		canvas_draw_rectangle(
			canvas, (const Rectangle_t *)&rect_1, &red);
		canvas_update(canvas);

		frame++;
		if (frame % 50 == 0) {
			snprintf(title,
				 TITLE_LEN, "MyPhysicsSim FPS: %f", 1/dt);
			canvas_set_title(canvas, title);
		}

		uint64_t t_1 = SDL_GetTicks64();
		dt = (t_1 - t_0) / 1000.0;
	}

	canvas_delete(canvas);
	return 0;
}
