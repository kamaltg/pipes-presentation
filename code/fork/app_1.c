#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    pid_t fils_pid;
    int stat;

    fils_pid = fork();

    if (fils_pid == 0) {
        printf("Fils avec pid=%d fils_pid=%d\n", getpid(), fils_pid);
        // force exit of child process
        exit(1);  // ~ 0
    } else if (fils_pid > 0) {
        wait(&stat);
        printf("Parent avec pid=%d fils_pid=%d stat=%d\n", getpid(), fils_pid, WIFEXITED(stat));
    } else {
        perror("fork\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
