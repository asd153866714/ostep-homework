#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    int x = 100;
   
	int rc = fork();
    
	if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
		printf("x value is %d in child (pid:%d)\n", x, (int)getpid());
    } else {
        // parent
        printf("x value is %d in parent (pid:%d)\n", x, (int)getpid());
    }
    return 0;
}
