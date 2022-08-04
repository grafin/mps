#include <log.h>
#include <canvas.h>

#include <stdbool.h>
#include <SDL2/SDL.h>

/**
 * Private members for struct Canvas.
 */
struct CanvasPrivate {
	/**
	 * Flag, set to false before SDL is initialized, to true, after
	 * successful initialization.
	 */
	bool sdl_initialized;

	/**
	 * Window for the canvas.
	 */
	SDL_Window *window;

	/**
	 * Renderer for the canvas.
	 */
	SDL_Renderer *renderer;
};

struct Canvas *
canvas_create(unsigned int width, unsigned int height)
{
	struct CanvasPrivate *canvasPrivate = calloc(
		1, sizeof(struct CanvasPrivate));
	if (canvasPrivate == NULL)
		mps_log(CRITICAL,
			"Failed to allocate memory for canvasPrivate.");

	struct Canvas *canvas = calloc(1, sizeof(struct Canvas));
	if (canvas == NULL) {
		free(canvasPrivate);
		mps_log(CRITICAL,
			"Failed to allocate memory for canvas.");
	}
	canvas->_p = canvasPrivate;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		free(canvas);
		free(canvasPrivate);
		mps_log(CRITICAL,
			"SDL could not initialize! SDL_Error: %s\n",
			SDL_GetError());
	}

	canvasPrivate->window = SDL_CreateWindow(
		"My SDL window",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width,
		height,
		SDL_WINDOW_SHOWN
	);
	if (canvasPrivate->window == NULL) {
		SDL_Quit();
		free(canvas);
		free(canvasPrivate);
		mps_log(CRITICAL,
			"Window could not be created! SDL_Error: %s\n",
			SDL_GetError());
	}

	canvasPrivate->renderer = SDL_CreateRenderer(
		canvasPrivate->window, -1, 0);
	if (canvasPrivate->renderer == NULL) {
		SDL_DestroyWindow(canvasPrivate->window);
		SDL_Quit();
		free(canvas);
		free(canvasPrivate);
		mps_log(CRITICAL,
			"Renderer could not be created! SDL_Error: %s\n",
			SDL_GetError());
	}

	if (SDL_SetRenderDrawBlendMode(canvasPrivate->renderer,
				       SDL_BLENDMODE_NONE) < 0) {
		SDL_DestroyRenderer(canvasPrivate->renderer);
		SDL_DestroyWindow(canvasPrivate->window);
		SDL_Quit();
		free(canvas);
		free(canvasPrivate);
		mps_log(CRITICAL,
			"Could not set blend mode! SDL_Error: %s\n",
			SDL_GetError());
	}

	return canvas;
}

int
canvas_update(struct Canvas *canvas)
{
	SDL_RenderPresent(canvas->_p->renderer);
	return 0;
}

int
canvas_delete(struct Canvas *canvas)
{
	SDL_DestroyRenderer(canvas->_p->renderer);
	SDL_DestroyWindow(canvas->_p->window);
	SDL_Quit();
	free(canvas->_p);
	free(canvas);
	return 0;
}

/**
 * Change current renderer color.
 */
static int
canvas_set_color(struct Canvas *canvas, const struct Color *color)
{
	int rc = SDL_SetRenderDrawColor(canvas->_p->renderer,
					color->r, color->g, color->b, color->a);
	if (rc < 0)
		mps_log(ERROR,
			"Failed to set renderer color! SDL_Error: %s\n",
			SDL_GetError());

	return rc;
}

int
canvas_fill(struct Canvas *canvas, const struct Color *color)
{
	int rc = canvas_set_color(canvas, color);
	if (rc < 0)
		goto out;

	rc = SDL_RenderClear(canvas->_p->renderer);
	if (rc < 0)
		mps_log(ERROR,
			"Failed to fill renderer! SDL_Error: %s\n",
			SDL_GetError());

out:
	return rc;
}

int
canvas_draw_point2d(struct Canvas *canvas,
		    const struct Vector2D *pos, const struct Color *color)
{
	int rc = canvas_set_color(canvas, color);
	if (rc < 0)
		goto out;

	rc = SDL_RenderDrawPointF(canvas->_p->renderer, pos->x, pos->y);
	if (rc < 0)
		mps_log(ERROR, "Failed to draw Vector2D!");

out:
	return rc;
}

int
canvas_draw_rectangle(struct Canvas *canvas,
		      const struct Rectangle *rect, const struct Color *color)
{
	struct Vector2D end;
	vector2d_init(&end, rect->x + rect->width, rect->y + rect->height);

	struct Vector2D p;
	vector2d_init(&p, 0, 0);

	int rc = 0;
	for (p.y = rect->y; p.y < end.y; p.y++) {
		for (p.x = rect->x; p.x < end.x; p.x++) {
			rc = canvas_draw_point2d(canvas, &p, color);
			if (rc < 0)
				goto out;
		}
	}

out:
	vector2d_delete(&p);
	vector2d_delete(&end);
	return rc;
}

int
canvas_draw_circle(struct Canvas *canvas,
		   const struct Circle *circle, const struct Color *color)
{
	double r = circle->r;
	int rc = 0;
	struct Vector2D p;
	vector2d_init(&p, 0, 0);

	for (double dy = -r; dy < r; dy++) {
		for (double dx = -r; dx < r; dx++) {
			if (dx * dx + dy * dy < r * r) {
				p.x = circle->x + dx;
				p.y = circle->y + dy;
				rc = canvas_draw_point2d(canvas, &p, color);
				if (rc < 0)
					goto out;

			}
		}
	}

out:
	vector2d_delete(&p);
	return rc;
}

void
canvas_set_title(struct Canvas *canvas, const char *title)
{
	SDL_SetWindowTitle(canvas->_p->window, title);
}
