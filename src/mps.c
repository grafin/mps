#include <log.h>
#include <canvas.h>
#include <phys/universe.h>
#include <phys/rectangle.h>
#include <phys/circle.h>

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

void
draw_phys_object(struct Canvas *canvas,
		 const struct PhysObject *obj,
		 const struct Color *color)
{
	switch (obj->type) {
	case PHYS_CIRCLE:
		canvas_draw_circle(
			canvas,
			&((struct PhysCircle *)obj)->circle,
			color);
		break;
	case PHYS_RECTANGLE:
		canvas_draw_rectangle(
			canvas,
			&((struct PhysRectangle *)obj)->rect,
			color);
		break;
	default:
		break;
	}
}

int
main(void)
{
	bool running = true;
	char title[TITLE_LEN + 1];
	SDL_Event e;

	struct Color black = {0x00, 0x00, 0x00, 0xFF};
	struct Color white = {0xFF, 0xFF, 0xFF, 0xFF};

	struct PhysRectangle rect;
	phys_rectangle_init(&rect, 0, 0, 100, 100, 400, 100);

	struct PhysCircle circle_1;
	phys_circle_init(&circle_1, 100, 200, 50, 200, 200);

	struct PhysCircle circle_2;
	phys_circle_init(&circle_2, 300, 100, 50, 200, 200);

	struct PhysObject *objects[] = {
		(struct PhysObject *)&rect,
		(struct PhysObject *)&circle_1,
		(struct PhysObject *)&circle_2,
		NULL,
	};

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

		if (canvas_fill(canvas, &black) != 0) {
			canvas_delete(canvas);
			return -1;
		}

		for (int i = 0; objects[i]; i++)
			objects[i]->collide(
				objects[i],
				(const struct PhysObject **)objects);

		for (int i = 0; objects[i]; i++) {
			objects[i]->move(objects[i], dt);
			draw_phys_object(canvas, objects[i], &white);
		}
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

	circle_delete(&circle_1);
	circle_delete(&circle_2);
	rectangle_delete(&rect);
	canvas_delete(canvas);
	return 0;
}
