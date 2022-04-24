#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>

int main() {
    struct timeval start, end;
    int n = 10000;
    double t = 0;
    double avg_time = 0;
	
	int fd = open("test.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
	if (fd < 0) {
		fprintf(stderr, "open fail");
		exit(1);
	}
	
    gettimeofday(&start, NULL);
    // run read() systemcl call 10000 times
    for (int i = 0; i < 10000; i++) {
        read(fd, NULL, 0);
    }
    gettimeofday(&end, NULL);
    
    // transfer second to microsecond, and calculate difference between start and end
    t = end.tv_sec * 1000000 + end.tv_usec - start.tv_sec * 1000000 - start.tv_usec;
    // calculate average cost of 10000 systemcall
    avg_time = t / n;
    printf("The costs of a system call is %f microsecond\n", avg_time);

    return 0;
}
