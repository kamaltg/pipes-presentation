#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    int fd;
    char msg[] = "Bonjour du père";

    fd = open("mon_pipe", O_WRONLY);

    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    write(fd, msg, strlen(msg) + 1);

    close(fd);

    return 0;
}
