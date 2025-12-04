#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
    int pid;
    for (int i = 0; i < 5; i++) {
        pid = fork();
        if (pid == 0) {
            printf("Soy %d, creado en iteración %d, mi PPID es %d\n", getpid(), i, getppid());
            sleep(25);
            exit(i);
        } else if (i == 4) {
            printf("Soy PAPI %d, mi PPID es %d\n", getpid(), getppid());
            sleep(10);
            exit(0);
        }
    }
}
