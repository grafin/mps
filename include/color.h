#ifndef COLOR_H_
#define COLOR_H_

/**
 * Structure representing RGBA color.
 */
struct Color {
	/**
	 * Red amount.
	 */
	unsigned char r;

	/**
	 * Green amount.
	 */
	unsigned char g;

	/**
	 * Blue amount.
	 */
	unsigned char b;

	/**
	 * Alpha amount.
	 */
	unsigned char a;
};

/**
 * Print color to stdout.
 */
void
color_print(const struct Color *color);

#endif /* COLOR_H_ */
