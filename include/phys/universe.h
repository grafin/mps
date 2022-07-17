#ifndef UNIVERSE_H_
#define UNIVERSE_H_

/**
 * Strcut that describes physical universe of the simulation.
 */
struct Universe {
	double left_boundary, right_boundry, top_boundary, bottom_boundary;
};

/**
 * Universe for the simulation.
 */
extern struct Universe universe;

/**
 * Initialize physical universe for the simulation.
 */
void
universe_init(double left_boundary, double right_boundry,
	      double top_boundary, double bottom_boundary);

#endif /* UNIVERSE_H_ */
