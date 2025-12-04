#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
    int pid = fork();

    if (pid == 0) {
        printf("I'm the child process %d (PID), %d (PPID)\n", getpid(), getppid());
    } else {
        printf("I'm the father process %d (PID), %d (PPID)\n", getpid(), getppid());
    }

    return 0;
}
