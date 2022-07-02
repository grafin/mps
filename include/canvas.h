#ifndef CANVAS_H_
#define CANVAS_H_

#include "color.h"
#include "vector2d.h"
#include "rectangle.h"

struct CanvasPrivate;

typedef struct Canvas {
	struct CanvasPrivate *_p;
} Canvas_t;

Canvas_t *canvas_create(unsigned int width, unsigned int height);
int canvas_update(Canvas_t *);
int canvas_delete(Canvas_t *);

int canvas_fill(Canvas_t *, const Color_t *);
int canvas_draw_point2d(Canvas_t *, const Vector2D_t *, const Color_t *);
int canvas_draw_rectangle(Canvas_t *, const Rectangle_t *, const Color_t *);

#endif /* CANVAS_H_ */
