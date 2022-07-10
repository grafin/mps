#ifndef VECTOR_2D_H_
#define VECTOR_2D_H_

typedef struct Vector2D {
	double x, y;
} Vector2D_t;

void vector2d_print(const Vector2D_t*);

Vector2D_t *vector2d_sum(Vector2D_t*, const Vector2D_t*, const Vector2D_t*);
Vector2D_t *vector2d_dif(Vector2D_t*, const Vector2D_t*, const Vector2D_t*);
Vector2D_t *vector2d_mul_float(Vector2D_t*, const Vector2D_t*, const float);

Vector2D_t *vector2d_flip_hor(Vector2D_t *v);
Vector2D_t *vector2d_flip_ver(Vector2D_t *v);

#endif /* VECTOR_2D_H_ */
