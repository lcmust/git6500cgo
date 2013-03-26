/* filename: learn_c.c
 * project: learn_c
 * compile method: gcc learn_c.c  -g -Wall  ./lib/lib_learn_c_mylib.o ./lib/lib_timer.o -o ./bin/learn_c
 * run: LD_LIBRARY_PATH=./lib ./bin/learn_c < input_file
 * date: 20120124-1238
 * author: chengl6500
 */
#include "learn_c.h"
#include "timer.h"

int main(void)
{
	struct timert t1;
	struct timert *t = &t1;
	if (timer_start(t)) {
		exit(-1);
	}

	int c;
	while((c = getchar()) != EOF) {
		putchar(c);
	}

	mylib_func1();

	printf("\nEND\n");
	if (timer_stop (t)) {
		exit(-1);
	}
	printf("this program taked %ld useconds!\n", timer_delta_useconds(t));
	exit(0);
}