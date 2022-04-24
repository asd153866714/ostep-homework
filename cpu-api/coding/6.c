#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
	
int main(int argc, char *argv[]) {

	int rc = fork();
	
	if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
		printf("child (pid:%d)\n",  getpid());
		int wc = waitpid(rc, NULL, WUNTRACED);
        printf("return value of waitpid is %d in child\n", wc);
    } else {
        // parent
        int wc = waitpid(rc, NULL, WUNTRACED);
		printf("parent (pid:%d)\n", getpid());
		printf("return value of waitpid is %d in parent\n", wc);
    }
    return 0;
}
