#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(int argc, char *argv[]) {
    int pid;
    for (int i = 0; i < 4; i++) {
        pid = fork();
        if (pid == 0) {
            printf("Soy hijo %d, con PID %d, y PPID  %d\n", i, getpid(), getppid());
            sleep(10);
            exit(i);
        } else {
            int stat_loc;
            wait(&stat_loc);
            printf("Soy PAPI %d, con PID %d, PPID %d y status: %d\n", i, getpid(), getppid(), stat_loc);
        }
    }
}
