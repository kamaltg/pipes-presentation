#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
    int fd;

    fd = open("does_not_exist", O_RDONLY);
    if (fd == -1) {
        perror("Erreur open()");
        return (1);
    }
    close(fd);
    return (0);
}
