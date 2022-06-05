#ifndef COLOR_H_
#define COLOR_H_

typedef struct Color {
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
} Color_t;

void color_print(const Color_t *);

#endif /* COLOR_H_ */
