#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
	
int main(int argc, char *argv[]) {

	int rc = fork();
    
	if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
		printf("child (pid:%d)\n",  getpid());
		printf("hello\n");
    } else {
        // parent
        sleep(1);
		printf("parent (pid:%d)\n", getpid());
		printf("goodbye\n");
    }
    return 0;
}
