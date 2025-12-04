#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
    int pid;
    for (int i = 0; i < 5; i++) {
        pid = fork();
        if (pid == 0) {
            printf("Soy %d, mi PPID es %d\n", getpid(), getppid());
            break;
        } else {
            printf("Soy PAPI %d, mi PPID es %d\n", getpid(), getppid());
        }
    }
}
