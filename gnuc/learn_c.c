/* filename: learn_c.c
 * project: learn_c
 * compile method: gcc learn_c.c  -g -Wall  ./lib/lib_learn_c_mylib.o ./lib/lib_timer.o -o ./bin/learn_c
 * make: make -f learn_c.makefile // all in One
 * run: ./bin/learn_c
 * make2: make -f learc_c_so.makefile // call ./lib/{*}.so
 * run2: LD_LIBRARY_PATH=./lib ./bin/learn_c < input_file
 * date: 20120124-1238
 * author: chengl6500
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "learn_c.h"
#include "timer.h"
#include "show_bytes.h"
#include "getopt_long.h"
#define DEBUG_LOG_ENABLE
#include "debug_log.h"

int lookup_word(char *word, char *array[]);
char *month_names[] = {
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December",
	NULL
};

struct option longopts[] = {
	{"file", required_argument, NULL, 'f'},
	{"test", no_argument, NULL, 't'},
	{"help", no_argument, NULL, 'h'},
	{"version", no_argument, NULL, 'v'},
	{0, 0, 0, 0}
};
struct msg_help_ver msg = {
	/* "help message:\n -f/--file <filename> File Name\n -t/--test Test Mode\n -h/--help Help Message\n -v/--version Show Version\n", */
	"help message:\n\
 	    -f/--file <filename> File Name\n			\
 		-t/--test Test Mode\n\
 		-h/--help Help Message\n\
 		-v/--version Show Version\n",  // help
	"version 0.1"  // version
};

struct option_arguments myargument = {
	NULL,   // filename
	0       // mode
};

int main(int argc, char *argv[])
{
	struct timert t1;
	struct timert *t1Ptr = &t1;
	if (timer_start(t1Ptr)) {
		exit(-1);
	}

	process_optlong(argc, argv, msg, &myargument, longopts);
	print_arguments(myargument);
	DEBUG_PRINT("%s", "****DEBUG_LOG_ENABLE****");

	if (!myargument.filename) {
		myargument.filename = "/home/love/dic.txt";
	}
	int fd;
	fd = open(myargument.filename, O_RDONLY);
	if (!fd) {
		printf("can't open file(%s)\n", myargument.filename);
		exit(-1);
	}

	DEBUG_PRINT("file(%s)opened(%d)", myargument.filename, fd);
	FILE *fd_File;
	fd_File = fdopen(fd, "r");
	if (!fd_File) {
		printf("fdopen(fd) error....\n");
		exit(-1);
	}

	char buf[8192];
	int month_no;
	char *charPtrTmp;
	for (;;) {
		charPtrTmp = fgets(buf, sizeof(buf), fd_File);
		if (!charPtrTmp) {
			break;
		}
		if (myargument.mode) {
				printf("%s\n", buf);
		}
		buf[strlen(buf) - 1] = '\0';
		if (strlen(buf)  > 1) {
			month_no = lookup_word(buf, month_names);
			if (month_no >= 0) {
				printf("found at %2d(%s)\n", month_no, month_names[month_no]);
			} else if (myargument.mode) {
				printf("%d\t\n", month_no);
			}
		}
	}
	/* int c; */
	/* while((c = getchar()) != EOF) { */
	/* 	putchar(c); */
	/* } */

	mylib_func1();

	printf("\nEND\n");
	if (timer_stop (t1Ptr)) {
		exit(-1);
	}
	printf("this program taked %ld useconds!\n",
		   timer_delta_useconds(t1Ptr));
	exit(0);
}

int lookup_word(char *word, char *array[])
{
	int i;
	for (i = 0; array[i] != NULL; i++) {
		//if (strcmp(word, array[i]) == 0) {
		if (strncmp(word, array[i], strlen(word)) == 0) {
			if (myargument.mode) {
				printf("(%30s)'s length is %d\n", word, strlen(word));
			}
			return i;
  		}
	}
	return -1;
}

int abcd(void)
{
	int a;
	a = 200;
	if ( a < 300) {
		a++;
	}
	return 0;
}
