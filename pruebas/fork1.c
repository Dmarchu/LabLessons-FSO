#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

void f1() {
    printf("Hello niggers, I'm process %d and my daddy is %d\n", getpid(), getppid());
}

void f2() {
    fork();
    printf("Hello niggers, I'm process %d and my daddy is %d\n", getpid(), getppid());
}

void f3() {
    pid_t pid = fork();
    printf("Hello niggers, I'm process %d and my daddy is %d. Returning value: %d\n", getpid(), getppid(), pid);
}

void f4() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("I'm the child process %d\n", getpid());
    } else {
        printf("I'm the father process %d\n", getppid());
    }

    printf("Hello niggers, I'm process %d and my daddy is %d. Returning value: %d\n", getpid(), getppid(), pid);
}

void f5() {
    int v = 50;
    pid_t pid = fork();

    if (pid == 0) {
        v = 25;
        printf("I'm the child process %d and v is %d\n", getpid(), v);
    } else {
        v = 100;
        printf("I'm the father process %d and v is %d\n", getppid(), v);
    }

    printf("Hello niggers, I'm process %d and my daddy is %d. Returning value: %d. V: %d\n", getpid(), getppid(), pid, v);
}

void f6() {
    int v = 50;
    pid_t pid = fork();

    if (pid == 0) {
        v = 25;
        printf("I'm the child process %d and v is %d\n", getpid(), v);
    } else {
        v = 100;
        printf("I'm the father process %d and v is %d\n", getppid(), v);
        sleep(2);
    }

    printf("Hello niggers, I'm process %d and my daddy is %d. Returning value: %d. V: %d\n", getpid(), getppid(), pid, v);
}

void f7() {
    int nigger;
    printf("Enter the number of iterations to the child process: ");
    scanf("%d", &nigger);
    printf("\n");
    for (int i = 0; i < 5; i++) {
        int v = 50;
        pid_t pid = fork();

        if (pid == 0) {
            v = 25;
            printf("I'm the child process %d and v is %d\n", getpid(), v);
        } else {
            v = 100;
            printf("I'm the father process %d and v is %d\n", getppid(), v);
            break;
        }

        printf("Hello niggers, I'm process %d and my daddy is %d. Returning value: %d. V: %d\n", getpid(), getppid(), pid, v);
    }
}

void f8() {
    int v = 50;
    pid_t pid = fork();

    if (pid == 0) {
        v = 25;
        printf("I'm the child process %d and v is %d\n", getpid(), v);
        int retval = execl("/bin/lsu", "ls", "-l", NULL);
        printf("retval = %d\n", retval);
    } else {
        v = 100;
        printf("I'm the father process %d and v is %d\n", getppid(), v);
        sleep(2);
    }

    printf("Hello niggers, I'm process %d and my daddy is %d. Returning value: %d. V: %d\n", getpid(), getppid(), pid, v);
}

void f9() {
    int v = 50;
    pid_t pid = fork();

    if (pid == 0) {
        v = 25;
        printf("I'm the child process %d and v is %d\n", getpid(), v);
        sleep(2);
        exit(12);
    } else {
        v = 100;
        printf("I'm the father process %d and v is %d\n", getppid(), v);
        int status;
        wait(&status);
        printf("Status en el padre es: %d\n", status);
    }

    printf("Hello niggers, I'm process %d and my daddy is %d. Returning value: %d. V: %d\n", getpid(), getppid(), pid, v);
}

void f10() {
    int v = 50;
    pid_t pids[5];

    for (int i = 0; i < 5; i++) {
        pids[i] = fork();
        if (pid == 0) {
            printf("I'm the child process %d and v is %d\n", getpid(), v);
            sleep(2);
            exit(8);
        }
    }

    for (int i = 0; i < 5; i++) {
        int status;
        wait(&status);
        printf("Status en el padre es: %d\n", status);
    }

    if (pid == 0) {
        v = 25;
        printf("I'm the child process %d and v is %d\n", getpid(), v);
        sleep(2);
        exit(12);
    } else {
        v = 100;
        printf("I'm the father process %d and v is %d\n", getppid(), v);
    }

    printf("Hello niggers, I'm process %d and my daddy is %d. Returning value: %d. V: %d\n", getpid(), getppid(), pid, v);
}

int main() {
    int selection;
    printf("Introduzca un número de ejercicio sobre fork(): ");
    scanf("%d", &selection);
    printf("\n");
    switch (selection) {
        case 1: f1();
            break;
        case 2: f2();
            break;
        case 3: f3();
            break;
        case 4: f4();
            break;
        case 5: f5();
            break;
        case 6: f6();
            break;
        case 7: f7();
            break;
        case 8: f8();
            break;
        case 9: f9();
            break;
        default: printf("Ese ejercicio no existe.\n");
            break;
    }
    return 0;
}
