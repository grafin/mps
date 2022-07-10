#ifndef UNIVERSE_H_
#define UNIVERSE_H_

typedef struct Universe {
	double left_boundary, right_boundry, top_boundary, bottom_boundary;
} Universe_t;

extern Universe_t universe;

void universe_init(double left_boundary, double right_boundry,
		   double top_boundary, double bottom_boundary);

#endif /* UNIVERSE_H_ */
