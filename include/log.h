#ifndef MPS_LOG_H_
#define MPS_LOG_H_

#include <util.h>

enum LogType {
	INFO=0,
	WARNING,
	ERROR,
	CRITICAL,
};

void
__printf(2, 3)
mps_log(enum LogType t, const char *fmt, ...);

#endif /* MPS_LOG_H_ */
