#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int i, j, k;
    int n = 5;
    pid_t fils_pid;

    for (i = 1; i <= n; i++) {
        fils_pid = fork();

        if (fils_pid > 0) {
            break;
        }
    }

    if (fils_pid > 0) {
        printf("iteration %d: Processus %d avec père %d\n", i, fils_pid, getpid());
    }

    for (j = 1; j < 100000; j++) {
        for (k = 1; k < 1000; k++) {
        }
    }

    return 0;
}
