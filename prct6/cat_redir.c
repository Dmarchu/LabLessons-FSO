#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main (int argc, char *argv[]) {
    int fd;
    char *arch = "cat_entrada.txt";
    mode_t fd_mode = S_IRWXU; // file permissions
    fd = open(arch,O_RDWR | O_CREAT,fd_mode);
    if (dup2(fd, STDIN_FILENO) == -1) {
        printf("Error calling dup2");
        close(fd);
        exit(-1);
    }
    close(fd);
    execl("/bin/cat", "cat", NULL);
    return 0;
}
