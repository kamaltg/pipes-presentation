int main() {
    char msg_recevied[10];
    int d[2];
    printf("je suis le père\n");
    pipe(d);
    printf("creation du fils \n");
    int f = fork();
    if (f == 0) {
        printf("je suis le fils\n");
        printf("PID =%d\n", getpid());
        write(d[1], "bonjour", 7);
    } else if (f > 0) {
        printf("je suis toujours le père\n");
        read(d[0], msg_recevied, 7);
        printf(" Message reçu : %s\n ", msg_recevied);
    } else {
        printf("Erreur\n");
    }
    return 0;
}