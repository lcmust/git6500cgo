#ifndef __GETOPT_LONG_H
#define __GETOPT_LONG_H
#define _GNU_SOURCE
#include <getopt.h>
#include <unistd.h>

struct option_arguments {
	char *filename;
	unsigned int mode;
};

struct msg_help_ver {
	char *help;
	char *ver;
};

void print_help(char *msg);
void print_version(char *msg);
int process_optlong(int argc, char *argv[],
					struct msg_help_ver msg,
					struct option_arguments *argu,
					struct option *opts);
void print_arguments(const struct option_arguments argu);
#endif  // __GETOPT_LONG_H
