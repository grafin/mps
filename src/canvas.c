#include <canvas.h>

#include <stdbool.h>
#include <stdio.h>
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
		return NULL;

	struct Canvas *canvas = calloc(1, sizeof(struct Canvas));
	if (canvas == NULL) {
		free(canvasPrivate);
		return NULL;
	}
	canvas->_p = canvasPrivate;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n",
		       SDL_GetError());
		goto error;
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
		printf("Window could not be created! SDL_Error: %s\n",
		       SDL_GetError());
		SDL_Quit();
		goto error;
	}

	canvasPrivate->renderer = SDL_CreateRenderer(
		canvasPrivate->window, -1, 0);
	if (canvasPrivate->renderer == NULL) {
		printf("Renderer could not be created! SDL_Error: %s\n",
		       SDL_GetError());
		SDL_DestroyWindow(canvasPrivate->window);
		SDL_Quit();
		goto error;
	}

	if (SDL_SetRenderDrawBlendMode(canvasPrivate->renderer,
				       SDL_BLENDMODE_NONE) < 0) {
		printf("Could not set blend mode! SDL_Error: %s\n",
		       SDL_GetError());
		SDL_DestroyRenderer(canvasPrivate->renderer);
		SDL_DestroyWindow(canvasPrivate->window);
		SDL_Quit();
		goto error;
	}

	return canvas;
error:
	free(canvas);
	free(canvasPrivate);
	return NULL;
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
		printf("Failed to set renderer color! SDL_Error: %s\n",
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
		printf("Failed to fill renderer! SDL_Error: %s\n",
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
		printf("Failed to draw Vector2D!");

out:
	return rc;
}

int
canvas_draw_rectangle(struct Canvas *canvas,
		      const Rectangle_t *rect, const struct Color *color)
{
	struct Vector2D end = {
		rect->start.x + rect->width, rect->start.y + rect->height};

	struct Vector2D p = {0};
	int rc = 0;
	for (p.y = rect->start.y; p.y < end.y; p.y++) {
		for (p.x = rect->start.x; p.x < end.x; p.x++) {
			rc = canvas_draw_point2d(canvas, &p, color);
			if (rc < 0)
				goto out;
		}
	}

out:
	return rc;
}

int
canvas_draw_circle(struct Canvas *canvas,
		   const Circle_t *circle, const struct Color *color)
{
	double r = circle->radius;
	int rc = 0;

	for (double dy = -r; dy < r; dy++) {
		for (double dx = -r; dx < r; dx++) {
			if (dx * dx + dy * dy < r * r) {
				struct Vector2D p = {circle->center.x + dx,
						circle->center.y + dy};
				rc = canvas_draw_point2d(canvas, &p, color);
				if (rc < 0)
					goto out;
			}
		}
	}

out:
	return rc;
}

void
canvas_set_title(struct Canvas *canvas, const char *title)
{
	SDL_SetWindowTitle(canvas->_p->window, title);
}
