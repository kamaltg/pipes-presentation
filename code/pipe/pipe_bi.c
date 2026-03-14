#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int p1[2];  // pipe père->fils
    int p2[2];  // pipe fils->père
    pid_t f;
    ssize_t n;
    int stat;

    if (pipe(p1) == -1 || pipe(p2) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    f = fork();

    if (f < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (f == 0) {
        close(p1[1]);  // fils ne écrit pas dans p1
        close(p2[0]);  // fils ne lit pas dans p2

        char msg_from_parent[100];

        n = read(p1[0], msg_from_parent, sizeof(msg_from_parent) - 1);
        if (n == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        msg_from_parent[n] = '\0';
        printf("Fils a reçu: %s\n", msg_from_parent);

        char reply[] = "Bonjour père";

        if (write(p2[1], reply, strlen(reply) + 1) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        close(p1[0]);
        close(p2[1]);
        exit(0);
    }

    else {
        close(p1[0]);  // père ne lit pas p1
        close(p2[1]);  // père ne écrit pas p2

        char msg[] = "Bonjour fils";

        if (write(p1[1], msg, strlen(msg) + 1) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        char reply[100];

        n = read(p2[0], reply, sizeof(reply) - 1);
        if (n == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        reply[n] = '\0';
        printf("Père a reçu: %s\n", reply);

        close(p1[1]);
        close(p2[0]);

        wait(&stat);
    }

    return 0;
}
