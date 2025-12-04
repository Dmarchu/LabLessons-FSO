#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main (int argc, char *argv[]) {
    char* argumentos[] = {"ls", "-R", "/", 0};
    pid_t childpid = fork();
    if (childpid == -1) {
        printf("fork failed\n");
        exit(1);
    } else if (childpid == 0) {
        if (execvp("bin/ls", argumentos) < 0) {
            printf("Could not execute: ls\n");
            exit(1);
        }
        int status;
        int x = wait(&status);
        if (x != childpid) {
            printf("Child has been interrupted\n");
        }
    }
    exit(0);
}
