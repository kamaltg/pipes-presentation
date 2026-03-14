#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];
    ssize_t n;

    fd = open("mon_pipe", O_RDONLY);

    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    n = read(fd, buffer, sizeof(buffer) - 1);

    if (n == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    buffer[n] = '\0';

    printf("Message reçu: %s\n", buffer);

    close(fd);

    return 0;
}
