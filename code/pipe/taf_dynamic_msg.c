#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int d[2];  // d[0] = lecture, d[1] = écriture
    pid_t pid_child;
    int stat;

    if (pipe(d) == -1) {
        perror("Erreur pipe()");
        exit(EXIT_FAILURE);
    }

    pid_child = fork();

    if (pid_child < 0) {
        perror("Erreur fork()");
        exit(EXIT_FAILURE);
    }

    /**
     * Fils
     */
    if (pid_child == 0) {
        const char* message = "Bonjour le monde dslaldk kkldsa!";
        size_t bytes = strlen(message) + 1;

        printf("Je suis le fils PID=%d\n", getpid());

        close(d[0]);  // le fils ne lit pas

        // envoyer la taille
        if (write(d[1], &bytes, sizeof(bytes)) != sizeof(bytes)) {
            perror("Erreur write taille");
            exit(EXIT_FAILURE);
        }

        // envoyer le message
        if (write(d[1], message, bytes) != bytes) {
            perror("Erreur write message");
            exit(EXIT_FAILURE);
        }

        close(d[1]);
        exit(EXIT_SUCCESS);
    }

    /**
     * Père
     */
    else {
        size_t bytes_read;
        char* message_received;

        printf("Je suis le père PID=%d\n", getpid());

        close(d[1]);  // le père n'écrit pas

        // lire la taille
        if (read(d[0], &bytes_read, sizeof(bytes_read)) != sizeof(bytes_read)) {
            perror("Erreur read taille");
            exit(EXIT_FAILURE);
        }

        // allocation mémoire
        message_received = malloc(bytes_read);
        if (message_received == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        // lire le message
        if (read(d[0], message_received, bytes_read) != bytes_read) {
            perror("Erreur read message");
            free(message_received);
            exit(EXIT_FAILURE);
        }

        printf("Message reçu : %s\n", message_received);

        free(message_received);
        close(d[0]);

        wait(&stat);
        if (WIFEXITED(stat)) {
            printf("Le fils s'est terminé avec le code %d\n", WEXITSTATUS(stat));
        }
    }

    return 0;
}