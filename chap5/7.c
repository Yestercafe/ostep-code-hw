#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {   // child process
        close(STDOUT_FILENO);
        printf("print after closing STDOUT_FILENO\n");
        // nothing output
    }
    else {                // parent process
        wait(NULL);
    }

    return 0;
}
