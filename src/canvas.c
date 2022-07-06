#include <canvas.h>

#include <stdbool.h>
#include <stdio.h>
#include <SDL2/SDL.h>

struct CanvasPrivate {
	bool sdl_initialized;
	SDL_Window *window;
	SDL_Renderer *renderer;
};

Canvas_t *canvas_create(unsigned int width, unsigned int height)
{
	struct CanvasPrivate *canvasPrivate = calloc(1,
		sizeof(struct CanvasPrivate));
	if (canvasPrivate == NULL)
		return NULL;

	Canvas_t *canvas = calloc(1, sizeof(Canvas_t));
	if (canvas == NULL) {
		free(canvasPrivate);
		return NULL;
	}
	canvas->_p = canvasPrivate;

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
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

int canvas_update(Canvas_t *canvas) {
	SDL_RenderPresent(canvas->_p->renderer);
	return 0;
}

int canvas_delete(Canvas_t *canvas) {
	SDL_DestroyRenderer(canvas->_p->renderer);
	SDL_DestroyWindow(canvas->_p->window);
	SDL_Quit();
	return 0;
}

static int canvas_set_color(Canvas_t *canvas, const Color_t *color) {
	if (SDL_SetRenderDrawColor(
	    canvas->_p->renderer, color->r, color->g, color->b, color->a) < 0) {
		printf("Failed to set renderer color! SDL_Error: %s\n",
			SDL_GetError());
		return -1;
	}
	return 0;
}


int canvas_fill(Canvas_t *canvas, const Color_t *color) {
	if (canvas_set_color(canvas, color) < 0)
		return -1;

	if (SDL_RenderClear(canvas->_p->renderer) < 0) {
		printf("Failed to fill renderer! SDL_Error: %s\n",
			SDL_GetError());
		return -1;
	}

	return 0;
}

int canvas_draw_point2d(Canvas_t *canvas, const Vector2D_t *p, const Color_t *c) {
	if (canvas_set_color(canvas, c) < 0)
		return -1;

	if (SDL_RenderDrawPointF(canvas->_p->renderer, p->x, p->y) < 0) {
		printf("Failed to draw Vector2D!");
		return -1;
	}
	return 0;
}

int canvas_draw_rectangle(Canvas_t *canvas, const Rectangle_t *r, const Color_t *c) {
	if (canvas_set_color(canvas, c) < 0)
		return -1;

	Vector2D_t p;
	for (double y = r->start.y; y < r->start.y + r->height; y++) {
		for (double x = r->start.x; x < r->start.x + r->width; x++) {
			p.x = x;
			p.y = y;
			if (canvas_draw_point2d(canvas, &p, c) < 0)
				return -1;
		}
	}

	return 0;
}

void canvas_set_title(Canvas_t *canvas, const char *title)
{
	SDL_SetWindowTitle(canvas->_p->window, title);
}
