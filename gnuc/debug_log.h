#ifndef __DEBUG_LOG_H
#define __DEBUG_LOG_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

//#define DEBUG_LOG_ENABLE
//add above line to the included file, then uncomment it.

#ifdef DEBUG_LOG_ENABLE
# define DEBUG_PRINT(format, args...)\
	log_message(__FILE__, __LINE__, __FUNCTION__, format, ##args);
#else
# define DEBUG_PRINT(format, args...)
#endif // DEBUG_LOG_ENABLE

static void log_message(char *file, int line, const char *func, const char *format, ...)
{
	if (format == NULL) {
		return;
	}

	int size = strlen(format) + 1024;
	char *new_format = (char *)malloc(sizeof(char) * size);
	if (new_format == NULL) {
		return;
	}
	memset(new_format, 0x00, size);
	snprintf(new_format, size, "[file: %s, func: %s, line: %d] %s\n", file, func, line, format);
	va_list va;
	va_start(va, format);
	vfprintf(stderr, new_format, va);
	va_end(va);

	free(new_format);
	return;
}

#endif  // __DEBUG_LOG_H
