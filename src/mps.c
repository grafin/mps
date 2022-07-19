#include <log.h>
#include <canvas.h>
#include <phys/universe.h>
#include <vector2d.h>
#include <rectangle.h>
#include <phys/rectangle.h>
#include <circle.h>

#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

/**
 * Screen dimension constants.
 */
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int TITLE_LEN = 255;

const float FPS = 60.0;

int
main(void)
{
	bool running = true;
	char title[TITLE_LEN + 1];
	SDL_Event e;

	struct Color black = {0x00, 0x00, 0x00, 0xFF};
	struct Color white = {0xFF, 0xFF, 0xFF, 0xFF};
	struct Color red = {0xFF, 0x00, 0x00, 0xFF};

	struct Vector2D start;
	vector2d_init(&start, 0, 0);

	struct Vector2D velocity;
	vector2d_init(&velocity, 400, 100);

	struct Rectangle rect = {start, 100, 100};
	struct PhysRectangle rect_1 = {{rect}, velocity};

	start.x = 250;
	start.y = 250;
	struct Circle circle = {start, 100};

	struct Canvas *canvas = canvas_create(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (canvas == NULL)
		return -1;
	universe_init(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);

	double dt = 0;
	uint64_t frame = 0;
	uint64_t T_0 = SDL_GetTicks64();
	while (running) {
		uint64_t t_0 = SDL_GetTicks64();

		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT)
				running = false;
		}

		phys_rectangle_move(&rect_1, dt);

		if (canvas_fill(canvas, &black) != 0) {
			canvas_delete(canvas);
			return -1;
		}
		canvas_draw_circle(canvas, &circle, &white);
		canvas_draw_rectangle(
			canvas, (const struct Rectangle *)&rect_1, &red);
		canvas_update(canvas);

		frame++;
		if (frame >= 50) {
			uint64_t T_1 = SDL_GetTicks64();
			double FPS = frame * 1000.0 / (T_1 - T_0);
			frame = 0;
			T_0 = T_1;

			snprintf(title,
				 TITLE_LEN, "MyPhysicsSim FPS: %f", FPS);
			canvas_set_title(canvas, title);
		}

		uint64_t t_1 = SDL_GetTicks64();
		dt = (t_1 - t_0) / 1000.0;
	}

	canvas_delete(canvas);
	return 0;
}
