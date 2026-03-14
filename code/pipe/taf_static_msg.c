#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int d[2];  // descripteur; d[0] = lecture, d[1] = écriture
    pid_t pid_child;  // PID du processus fils
    char message_received[1024];  // buffer pour recevoir le message
    ssize_t bytes_read;  // nombre de bytes lus
    int stat;  // état de terminaison du fils

    // Création du pipe
    if (pipe(d) < 0) {
        perror("Erreur pipe()");
        exit(EXIT_FAILURE);
    }

    // Création du processus fils
    pid_child = fork();

    if (pid_child < 0) {
        perror("Erreur fork()");
        exit(EXIT_FAILURE);
    }

    /**
     * PROCESSUS FILS
     */
    if (pid_child == 0) {
        // Le message
        const char* message = "Bonjour le monde!";

        printf("Je suis le fils PID=%d\n", getpid());

        // Le fils n'utilise pas la lecture
        close(d[0]);

        // Ecriture dans le pipe
        if (write(d[1], message, strlen(message) + 1) < 0) {
            perror("Erreur write()");
            exit(EXIT_FAILURE);
        }

        printf("Message envoye : %s\n", message);

        // Fermeture de l'extrémité d'écriture
        close(d[1]);

        exit(EXIT_SUCCESS);  // ou 0
    }

    /**
     * PROCESSUS PÈRE
     */
    else {
        printf("Je suis le père PID=%d\n", getpid());

        // Le père n'utilise pas l'écriture
        close(d[1]);

        // Lecture du message envoyé par le fils
        // bytes_read ne pourra jamais dépasser sizeof(message_received) - 1
        bytes_read = read(d[0], message_received, sizeof(message_received) - 1);
        if (bytes_read < 0) {
            perror("Erreur read()");
            exit(EXIT_FAILURE);
        }

        // Assurer l'ajout de caractère fin de chaîne '\0'
        message_received[bytes_read] = '\0';

        printf("Message reçu : %s\n", message_received);

        // Fermeture de l'extrémité de lecture
        close(d[0]);

        // Attendre la fin du fils et récupérer son état
        wait(&stat);
        if (WIFEXITED(stat)) {
            printf("Le fils s'est terminé avec le code %d\n", WEXITSTATUS(stat));
        }

        printf("Père terminé avec succès!\n");
    }

    return 0;
}
