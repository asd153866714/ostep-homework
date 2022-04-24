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
		
        close(STDOUT_FILENO);
		int fd = open("output.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
		if (fd < 0) {
			fprintf(stderr, "open fail");
			exit(1);
		}
		printf("ouput message after close(STDOUT_FILENO)\n");
    } else {
        // parent
		printf("parent (pid:%d)\n", getpid());
    }
    return 0;
}
