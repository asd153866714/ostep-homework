#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
	
int main(int argc, char *argv[]) {

	int rc = fork();
	
	if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
		printf("child (pid:%d)\n",  getpid());
		
		char *myargs[2];
		myargs[0] = strdup("/bin/ls");
		myargs[1] = NULL;
		// execvp(myargs[0], myargs);
		execv(myargs[0], myargs);
    } else {
        // parent
		printf("parent (pid:%d)\n", getpid());
    }
    return 0;
}
