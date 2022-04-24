#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
	
int main(int argc, char *argv[]) {

	int fd = open("hello.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
	if (fd < 0) {
		fprintf(stderr, "open fail");
		exit(1);
	}

	int rc = fork();
    
	if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
		printf("fd in child is %d (pid:%d)\n", fd, getpid());
    } else {
        // parent
		printf("fd in parent is %d (pid:%d)\n", fd, getpid());
    }
    return 0;
}
