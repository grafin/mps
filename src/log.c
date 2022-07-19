#include <log.h>

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

void
__printf(2, 3)
mps_log(enum LogType t, const char *fmt, ...)
{
	FILE *out = NULL;
	int rc = 0;
	va_list ap;
	va_start(ap, fmt);

	switch (t) {
	case CRITICAL:
		rc = -1;
		FALLTHROUGH;
	case ERROR:
		out = stderr;
		break;
	case INFO:
	case WARNING:
	default:
		out = stdout;
		break;
	}

	vfprintf(out, fmt, ap);
	va_end(ap);

	if (rc != 0)
		exit(rc);
}
