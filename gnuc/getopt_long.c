#include <stdio.h>
#include <stdlib.h>
#include "getopt_long.h"

void print_help(char *msg_help)
{
	printf("%s\n", msg_help);
	return;
}

void print_version(char *msg_version)
{
	printf("%s\n", msg_version);
	return;
}

int process_optlong(int argc, char *argv[],
					struct msg_help_ver msg,
					struct option_arguments *argu,
					struct option *longopts)
{
	int opt_no;
	int opt_run;
	while ((opt_no = getopt_long(argc, argv, ":f:hvt", longopts, &opt_run))
		   != -1) {
		switch (opt_no) {
		case 'h':
			print_help(msg.help);
			exit(0);
		case 'v':
			print_version(msg.ver);
			exit(0);
		case 'f':
			argu->filename = optarg;
			break;
		case 't':
			argu->mode = 1;
			break;
		case ':':
			printf("\nThis is %d argmuent(%c)!", optind, optopt);
			printf("Needs a value!\n");
			exit(-1);
		case '?':
			//printf("\nThis is %d argmuent!", optind);
			if (0 == optopt) {
				printf("unknown option:%c\n", '-');
			} else {
				printf("unknown option :%c\n", optopt);
			}
			exit(-2);
		}
	}
		
	printf("\n");
	return 0;
}

void print_arguments(const struct option_arguments argu)
{

	if (argu.filename) {
		printf("your filename is (%s)\n", argu.filename);
	} else {
		printf("you are not give file!\n");
	}
	if (argu.mode) {
		printf("your mode is (%d)\n", argu.mode);
	} else {
		printf("your mode is not set\n");
	}
	return;
}
