#ifndef CANVAS_H_
#define CANVAS_H_

#include "color.h"
#include "vector2d.h"
#include "rectangle.h"
#include "circle.h"

struct CanvasPrivate;

/**
 * Canvas, which can be used to draw on.
 */
struct Canvas {
	/**
	 * Private members of Canvas structure.
	 */
	struct CanvasPrivate *_p;
};

/**
 * Create canvas with desired width and height.
 */
struct Canvas *
canvas_create(unsigned int width, unsigned int height);

/**
 * Render canvas to screen.
 */
int
canvas_update(struct Canvas *canvas);

/**
 * Delete canvas and free all resources.
 */
int
canvas_delete(struct Canvas *canvas);

/**
 * Fill canvas with solid color.
 */
int
canvas_fill(struct Canvas *canvas, const struct Color *color);

/**
 * Draw single point in pos on canvas, using specified color.
 */
int
canvas_draw_point2d(struct Canvas *canvas,
		    const struct Vector2D *pos, const struct Color *color);

/**
 * Draw filled rect on canvas, using specified color.
 */
int
canvas_draw_rectangle(struct Canvas *canvas,
		      const struct Rectangle *rect, const struct Color *color);

/**
 * Draw filled circle on canvas, using specified color.
 */
int
canvas_draw_circle(struct Canvas *canvas,
		   const struct Circle *circle, const struct Color *color);

/**
 * Update title of canvas.
 */
void
canvas_set_title(struct Canvas *canvas, const char *title);

#endif /* CANVAS_H_ */
