#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int id = fork();
    printf("Hello from id: %d\n", id);
    return 0;
}
