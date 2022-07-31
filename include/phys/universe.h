#ifndef MPS_UNIVERSE_H_
#define MPS_UNIVERSE_H_

/**
 * Strcut that describes physical universe of the simulation.
 */
struct Universe {
	double left_boundary, right_boundary, top_boundary, bottom_boundary;
};

/**
 * Universe for the simulation.
 */
extern struct Universe universe;

/**
 * Initialize physical universe for the simulation.
 */
void
universe_init(double left_boundary, double right_boundary,
	      double top_boundary, double bottom_boundary);

#endif /* MPS_UNIVERSE_H_ */
