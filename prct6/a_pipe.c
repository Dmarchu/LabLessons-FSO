#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i;
    char *arguments1[] = {"ls", "-la", NULL};
    char *arguments2[] = {"wc", "-l", NULL};
    int fildes[2];
    pid_t pid;

    if (pipe(fildes) == -1) {
        fprintf(stderr, "Pipe creation failed\n");
        exit(-1);
    }

    for (i = 0; i < 2; i++) {
        pid = fork();
        if (pid == -1) {
            fprintf(stderr, "Fork failed\n");
            exit(-1);
        } else if (pid == 0) {
            if (i == 0) {
                close(fildes[0]); // Child process redirects its output to the pipe
                if (dup2(fildes[1], STDOUT_FILENO) == -1) { // Child process closes pipe descriptors
                    fprintf(stderr, "Error in dup2 for ls\n"); // Child process changes its memory image
                    exit(-1);
                }
                if (execvp("ls", arguments1) < 0) {
                    fprintf(stderr, "ls not found\n");
                    exit(-1);
                }
            } else if (i == 1) {
                close(fildes[1]); // Child process redirects its input to the pipe
                if (dup2(fildes[0], STDIN_FILENO) == -1) { // Child process closes pipe descriptors
                    fprintf(stderr, "Error in dup2 for wc\n"); // Child process changes its memory image
                    exit(-1);
                }
                if (execvp("wc", arguments2) < 0) {
                    fprintf(stderr, "wc not found\n");
                    exit(-1);
                }
            }
        }
    }

    close(fildes[0]);
    close(fildes[1]);
    for (i = 0; i < 2; i++) wait(NULL);
    return 0;
}
