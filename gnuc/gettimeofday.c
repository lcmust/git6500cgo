#include <stdio.h>
#include <sys/time.h>

int main(void)
{
	struct timeval tv;
	struct timezone tz;
	if (!gettimeofday(&tv, &tz)) {
		printf("tv_sec: %d\n", tv.tv_sec);
		printf("tv_usec: %d\n", tv.tv_usec);
		printf("tz_min: %d\n", tz.tz_minuteswest);
		printf("tz_dsttime: %d\n", tz.tz_dsttime);
	}
	exit(0);
}
