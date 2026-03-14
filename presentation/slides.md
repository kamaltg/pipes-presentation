---
theme: default
class: text-center
highlighter: shiki
transition: slide-left
---

# TAF 1 (TUBES/PIPES)

<div class="grid grid-cols-2 gap-4 mt-20 text-center">
  <div>
    <strong>Réalisée par:</strong><br>Kamal TAGHLAOUI
  </div>
  <div>
    <strong>Encadrée par:</strong><br>Pr. Abdellah OUAGUID
  </div>
</div>

---
transition: fade-out
layout: center
class: text-center
---

# LE CONTEXTE

<div v-click class="mt-8 px-24">

La <span class="text-blue-500 font-bold">communication interprocessus (IPC)</span> est un ensemble de mécanismes permettant la <span class="text-green-500 font-bold">communication</span> et la <span class="text-green-500 font-bold">synchronisation</span> entre processus.

> Les IPC disposent d’interfaces standardisées, notamment selon le Standard <span class="text-blue-500 font-bold">POSIX</span>.

</div>

---
transition: slide-up
---

# LES MÉCANISMES DE COMMUNICATION (IPC)

<div class="grid grid-cols-3 gap-8 mt-10 text-center">
  <div v-click="1">
    <div class="p-4 w-full h-full flex flex-col items-center justify-center overflow-hidden" v-mark.box.red="7">
      <h3 class="mb-2 text-xl font-bold w-full">Tubes (pipes)</h3>
      <div class="flex items-center justify-center gap-2 mt-4 h-10 w-full">
        <div class="bg-blue-100 border border-blue-500 text-blue-800 rounded px-2 py-1 text-sm font-bold">P1</div>
        <div class="relative w-24 h-2 bg-gray-200 mx-1 overflow-hidden rounded-full">
          <div class="absolute top-0 h-full w-4 bg-blue-500 rounded-full anim-pipe"></div>
        </div>
        <div class="bg-green-100 border border-green-500 text-green-800 rounded px-2 py-1 text-sm font-bold">P2</div>
      </div>
    </div>
  </div>
  <div v-click="2">
    <div class="p-4 w-full h-full flex flex-col items-center justify-center overflow-hidden">
      <h3 class="mb-2 text-xl font-bold w-full">Files de messages</h3>
      <div class="flex items-center justify-center gap-4 mt-4 h-10 w-full">
        <div class="bg-blue-100 border border-blue-500 text-blue-800 rounded px-2 py-1 text-sm font-bold">P1</div>
        <div class="flex gap-1 bg-yellow-100 border-2 border-yellow-500 px-2 py-1 rounded relative z-10">
          <div class="w-2 h-2 bg-yellow-500 rounded-full animate-bounce"></div>
          <div class="w-2 h-2 bg-yellow-500 rounded-full animate-bounce" style="animation-delay: 0.2s"></div>
          <div class="w-2 h-2 bg-yellow-500 rounded-full animate-bounce" style="animation-delay: 0.4s"></div>
        </div>
        <div class="bg-green-100 border border-green-500 text-green-800 rounded px-2 py-1 text-sm font-bold">P2</div>
      </div>
    </div>
  </div>
  <div v-click="3">
    <div class="p-4 w-full h-full flex flex-col items-center justify-center overflow-hidden">
      <h3 class="mb-2 text-xl font-bold w-full">Signaux</h3>
      <div class="flex items-center justify-between mt-4 h-10 w-32 mx-auto relative cursor-default">
        <div class="bg-blue-100 border border-blue-500 text-blue-800 rounded px-2 py-1 text-sm font-bold z-10 relative">P1</div>
        <div class="absolute inset-0 flex items-center justify-center z-0">
          <div class="text-3xl anim-flash select-none">⚡</div>
        </div>
        <div class="bg-green-100 border border-green-500 text-green-800 rounded px-2 py-1 text-sm font-bold z-10 relative">P2</div>
      </div>
    </div>
  </div>
  <div v-click="4">
    <div class="p-4 w-full h-full flex flex-col items-center justify-center overflow-hidden">
      <h3 class="mb-2 text-xl font-bold w-full">Sockets</h3>
      <div class="flex items-center justify-between mt-4 h-10 w-36 mx-auto relative cursor-default">
        <div class="bg-blue-100 border border-blue-500 text-blue-800 rounded px-2 py-1 text-sm font-bold z-10 relative">P1</div>
        <div class="absolute inset-0 flex items-center justify-center z-0 pt-1">
           <div class="relative w-16 h-4">
             <div class="absolute top-0 left-0 text-sm anim-socket-ltr">🌐</div>
             <div class="absolute bottom-0 right-0 text-sm anim-socket-rtl">🌐</div>
           </div>
        </div>
        <div class="bg-green-100 border border-green-500 text-green-800 rounded px-2 py-1 text-sm font-bold z-10 relative">P2</div>
      </div>
    </div>
  </div>
  <div v-click="5">
    <div class="p-4 w-full h-full flex flex-col items-center justify-center overflow-hidden">
      <h3 class="mb-1 text-xl font-bold w-full">Mémoire partagée</h3>
      <div class="flex items-center justify-center gap-4 mt-1 h-16 w-full cursor-default">
        <div class="flex flex-col gap-2 justify-center">
          <div class="bg-blue-100 border border-blue-500 text-blue-800 rounded px-2 text-xs font-bold leading-none py-1">P1</div>
          <div class="bg-green-100 border border-green-500 text-green-800 rounded px-2 text-xs font-bold leading-none py-1">P2</div>
        </div>
        <div class="flex flex-col items-center text-xs text-gray-400 font-bold justify-around h-full py-1">
          <div class="anim-swap-1 text-[10px] leading-none">↔</div>
          <div class="anim-swap-2 text-[10px] leading-none">↔</div>
        </div>
        <div class="w-16 h-12 bg-purple-100 border-2 border-purple-500 rounded flex flex-col items-center justify-center text-purple-800 text-xs font-bold anim-memory z-10 relative">
          <span class="opacity-80">RAM</span>
          <div class="flex gap-1 mt-1">
            <div class="w-1 h-2 bg-purple-400"></div>
            <div class="w-1 h-2 bg-purple-400"></div>
            <div class="w-1 h-2 bg-purple-400"></div>
          </div>
        </div>
      </div>
    </div>
  </div>
  <div v-click="6">
    <div class="p-4 w-full h-full flex flex-col items-center justify-center overflow-hidden">
      <h3 class="mb-1 text-xl font-bold w-full">Fichiers mappés</h3>
      <div class="flex flex-col items-center justify-center mt-1 h-14 w-full cursor-default">
        <div class="text-2xl z-10 bg-[var(--slidev-theme-background)] rounded leading-none">📄</div>
        <div class="flex gap-4 -mt-1 w-12 justify-between">
          <div class="text-[10px] text-gray-400 rotate-45 anim-up font-bold">↑</div>
          <div class="text-[10px] text-gray-400 -rotate-45 anim-up font-bold" style="animation-delay: 1s">↑</div>
        </div>
        <div class="flex justify-between w-20 -mt-1">
          <div class="bg-blue-100 border border-blue-500 text-blue-800 rounded px-2 text-[10px] py-1 font-bold leading-none">P1</div>
          <div class="bg-green-100 border border-green-500 text-green-800 rounded px-2 text-[10px] py-1 font-bold leading-none">P2</div>
        </div>
      </div>
    </div>
  </div>
</div>

<style>
@keyframes move-ltr { 0% { left: 0%; opacity: 0; } 10% { opacity: 1; } 90% { opacity: 1; left: 85%; } 100% { left: 100%; opacity: 0; } }
@keyframes flash-bolt { 0%, 100% { transform: scale(1); opacity: 0; } 50% { transform: scale(1.5); opacity: 1; color: #eab308; } }
@keyframes socket-ltr { 0% { transform: translate(0, 0) scale(0.5); opacity: 0; } 50% { transform: translate(30px, -5px) scale(1.2); opacity: 1; } 100% { transform: translate(60px, 0) scale(0.5); opacity: 0; } }
@keyframes socket-rtl { 0% { transform: translate(0, 0) scale(0.5); opacity: 0; } 50% { transform: translate(-30px, 5px) scale(1.2); opacity: 1; } 100% { transform: translate(-60px, 0) scale(0.5); opacity: 0; } }
@keyframes pulse-mem { 0%, 100% { box-shadow: 0 0 0px 0px rgba(168,85,247,0.2); } 50% { box-shadow: 0 0 10px 3px rgba(168,85,247,0.6); } }
@keyframes move-up { 0%, 100% { transform: translateY(0) rotate(var(--rot)); opacity: 0; } 50% { transform: translateY(-3px) rotate(var(--rot)); opacity: 1; } }

.anim-pipe { animation: move-ltr 1.5s linear infinite; }
.anim-flash { animation: flash-bolt 1.5s cubic-bezier(0.4, 0, 0.6, 1) infinite; }
.anim-socket-ltr { animation: socket-ltr 2s ease-in-out infinite; }
.anim-socket-rtl { animation: socket-rtl 2s ease-in-out infinite; }
.anim-memory { animation: pulse-mem 2s infinite; }
.anim-swap-1 { animation: flash-bolt 1.5s infinite; }
.anim-swap-2 { animation: flash-bolt 1.5s infinite 0.75s; }
.anim-up:first-child { --rot: 45deg; animation: move-up 2s infinite; }
.anim-up:last-child { --rot: -45deg; animation: move-up 2s infinite 1s; }
</style>

---
layout: center
---

# MÉTHODE DE TUBES (PIPES)

```c
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
        printf("Message reçu : %s\n", msg_recevied);
    } else {
        printf("Erreur\n");
    }
    return 0;
}
```

---

# TRAVAIL DEMANDÉ

À partir du programme fourni, vous devez :

<v-clicks>

- Proposer une version corrigée et **propre** du programme.
- Vérifier les appels système suivants : `pipe()`, `fork()`, `read()`, `write()`.
- Ajouter les **tests d’erreurs** nécessaires (`perror`, `exit`).
- Améliorer la **lisibilité** du code (nommage, indentation).
- Ajouter des **commentaires** expliquant chaque étape.

</v-clicks>

---
layout: center
class: text-center
---

# OBJECTIF

Le programme final doit permettre de manière robuste :

<div class="mt-8 text-2xl font-bold">
  <div v-click>
    👶 <strong>Au fils</strong> d’écrire dans le pipe.
  </div>
  
  <br/>

  <div v-click>
    👨 <strong>Au père</strong> de lire le message reçu.
  </div>
</div>

---
layout: center
---

# 0. CODE INITIAL

```c
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
        printf("Message reçu : %s\n", msg_recevied);
    } else {
        printf("Erreur\n");
    }
    return 0;
}
```

---
layout: center
---

# 1. DÉCLARATIONS ET INCLUSIONS

````md magic-move
```c
int main() {
    char msg_recevied[10]; 
    int d[2];

    // ... suite du programme ...
}
```

```c {*|1-6|9-13|*}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int d[2];                     // descripteur: d[0]=lecture, d[1]=écriture
    pid_t pid_child;              // PID du processus fils
    char message_received[1024];  // buffer de réception
    ssize_t bytes_read;           // nombre de bytes lus
    int stat;                     // état de terminaison du fils
    
    // ... suite du programme ...
}
```
````

---
layout: center
---

# 2. TESTS D'ERREURS PIPE ET FORK

````md magic-move
```c
int main() {
    // ...
    printf("je suis le père\n");
    pipe(d);
    printf("creation du fils \n");
    int f = fork();
    // ...
}
```

```c {*|3-8|9-15|*}
int main() {
    // ... 
    
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

    // ...
}
```
````

---
layout: center
---

# 3. LOGIQUE DU PROCESSUS FILS

````md magic-move
```c
    if (f == 0) {
        printf("je suis le fils\n");
        printf("PID=%d\n", getpid());
        write(d[1], "bonjour", 7);
    }
```

```c {*|2-3|5|7-8|10-14|16-17|19|*}
    if (pid_child == 0) {
        // Le message
        const char* message = "bonjour";

        printf("Je suis le fils PID=%d\n", getpid());

        // Le fils n'utilise pas la lecture
        close(d[0]);

        // Ecriture dans le pipe
        if (write(d[1], message, strlen(message) + 1) < 0) {
            perror("Erreur write()");
            exit(EXIT_FAILURE);
        }

        // Fermeture de l'extrémité d'écriture
        close(d[1]);

        exit(EXIT_SUCCESS);  // ou 0
    }
```
````

---
layout: center
---

# 4. LOGIQUE DU PROCESSUS PÈRE

```c
    else if (f > 0) {
        printf("je suis toujours le père\n");
        read(d[0], msg_recevied, 7);
        printf("Message reçu : %s\n", msg_recevied);
    }
```

---
layout: center
---

# 5. LOGIQUE DU PROCESSUS PÈRE

```c {*|2|4-5|7-12|7-12|14-15|17|19-20|22-26|*} {maxHeight:'350px'}
    else {
        printf("Je suis le père PID=%d\n", getpid());

        // Le père n'utilise pas l'écriture
        close(d[1]);

        // Lecture du message envoyé par le fils
        bytes_read = read(d[0], message_received, sizeof(message_received) - 1);
        if (bytes_read < 0) {
            perror("Erreur read()");
            exit(EXIT_FAILURE);
        }

        // Assurer l'ajout de '\0' à la fin du message
        message_received[bytes_read] = '\0';

        printf("Message reçu : %s\n", message_received);

        // Fermeture de l'extrémité de lecture
        close(d[0]);

        // Attendre la fin du fils et récupérer son état
        wait(&stat);
        if (WIFEXITED(stat)) {
            printf("Le fils s'est terminé avec le code %d\n", WEXITSTATUS(stat));
        }
    }
```

---
layout: center
---

# 6. VERSION FINALE

```c {all|1-6|15,20|27-40|44-63|all} {maxHeight:'460px'}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int d[2];
    pid_t pid_child;
    char msg_received[1024];
    ssize_t bytes_read;
    int stat;

    if (pipe(d) < 0) {
        perror("Erreur pipe()");
        exit(EXIT_FAILURE);
    }

    pid_child = fork();
    if (pid_child < 0) {
        perror("Erreur fork()");
        exit(EXIT_FAILURE);
    }

    if (pid_child == 0) {
        const char* message = "bonjour";

        printf("Je suis le fils PID=%d\n", getpid());

        close(d[0]);

        if (write(d[1], message, strlen(message) + 1) < 0) {
            perror("Erreur write()");
            exit(EXIT_FAILURE);
        }

        close(d[1]);

        exit(EXIT_SUCCESS);
    }

    else {
        printf("Je suis le père PID=%d\n", getpid());

        close(d[1]);

        bytes_read = read(d[0], message_received, sizeof(message_received) - 1);
        if (bytes_read < 0) {
            perror("Erreur read()");
            exit(EXIT_FAILURE);
        }

        message_received[bytes_read] = '\0';

        printf("Message reçu : %s\n", message_received);

        close(d[0]);

        wait(&stat);
        if (WIFEXITED(stat)) {
            printf("Le fils s'est terminé avec le code %d\n", WEXITSTATUS(stat));
        }
    }

    return 0;
}
```

---
layout: center
---

<div class="w-full flex-col flex items-center">
  <div class="transition-all duration-700 w-full" :class="$slidev.nav.clicks ? 'transform -translate-y-4' : 'transform translate-y-32'">
    <h1 class="text-center !mb-0 !mt-0">MESSAGE DE N'IMPORTE QUELLE TAILLE ?</h1>
  </div>
  <div v-click="1" class="w-full mt-24 flex items-start justify-center gap-16 px-4 transition-opacity duration-500">
    <!-- Zone P1 -->
    <div class="flex flex-col items-center">
      <!-- P1 : Processus récepteur -->
      <div class="w-48 h-32 border-4 border-blue-500 bg-blue-50 rounded-lg flex items-center justify-center shadow-md">
        <span class="text-xl font-bold text-blue-900">P1 (Lecteur)</span>
      </div>  
      <!-- Note malloc sous P1 -->
      <div class="mt-6 text-center w-full font-mono text-white text-lg font-bold drop-shadow-md">
        message = malloc(taille)
      </div>
    </div>
    <!-- Arrows Zone -->
    <div class="w-64 h-32 relative flex flex-col justify-center gap-12">
      <!-- Step 1 Arrow -->
      <div class="w-full flex flex-col items-center">
        <div class="text-sm font-bold mb-1">
          1. taille
        </div>
        <svg class="w-full h-4 overflow-visible" xmlns="http://www.w3.org/2000/svg">
          <line x1="100%" y1="50%" x2="15" y2="50%" stroke="#374151" stroke-width="4"/>
          <polygon points="15,0 15,16 0,8" fill="#374151"/>
        </svg>
      </div>
      <!-- Step 2 Arrow -->
      <div v-click="1" class="w-full flex flex-col items-center">
        <div class="text-sm font-bold mb-1">
          2. message
        </div>
        <svg class="w-full h-4 overflow-visible" xmlns="http://www.w3.org/2000/svg">
          <line x1="100%" y1="50%" x2="15" y2="50%" stroke="#374151" stroke-width="4"/>
          <polygon points="15,0 15,16 0,8" fill="#374151"/>
        </svg>
      </div>
    </div>
    <!-- P2 : Processus émetteur -->
    <div class="flex flex-col items-center">
      <div class="w-48 h-32 border-4 border-green-500 bg-green-50 rounded-lg flex items-center justify-center shadow-md">
        <span class="text-xl font-bold text-green-900">P2 (Écrivain)</span>
      </div>
    </div>
  </div>
</div>

---
layout: center
---

<div class="w-full flex-col flex items-center">
  <h1 class="text-center !mb-16 !mt-0 text-[32px] font-bold">
    Communication bidirectionnelle avec 2 pipes
  </h1>
  <div class="w-full flex items-start justify-center gap-12 px-4">
    <!-- PÈRE -->
    <div class="flex flex-col items-center">
      <div class="w-48 h-32 border-4 border-blue-500 bg-blue-50 rounded-lg flex flex-col items-center justify-center shadow-md">
        <span class="text-xl font-bold text-blue-900 mb-2">PÈRE</span>
      </div>
    </div>
    <!-- PIPES Zone -->
    <div class="w-64 h-32 relative flex flex-col justify-center gap-8">
      <!-- Pipe 1 -->
      <div class="w-full flex flex-col items-center">
        <div class="text-sm font-bold mb-1">
          Pipe 1
        </div>
        <div class="w-full flex items-center text-gray-700">
          <div class="h-1 w-full bg-gray-700"></div>
          <div class="w-0 h-0 border-t-[6px] border-t-transparent border-l-[12px] border-l-gray-700 border-b-[6px] border-b-transparent"></div>
        </div>
      </div>
      <!-- Pipe 2 -->
      <div class="w-full flex flex-col items-center">
        <div class="text-sm font-bold mb-1">
          Pipe 2
        </div>
        <div class="w-full flex items-center text-gray-700">
          <div class="w-0 h-0 border-t-[6px] border-t-transparent border-r-[12px] border-r-gray-700 border-b-[6px] border-b-transparent"></div>
          <div class="h-1 w-full bg-gray-700"></div>
        </div>
      </div>
    </div>
    <!-- FILS -->
    <div class="flex flex-col items-center">
      <div class="w-48 h-32 border-4 border-green-500 bg-green-50 rounded-lg flex flex-col items-center justify-center shadow-md">
        <span class="text-xl font-bold text-green-900 mb-2">FILS</span>
      </div>
    </div>
  </div>
</div>

---
layout: center
---

<div class="w-full flex-col flex items-center">
  <h1 class="text-center !mb-16 !mt-0 text-[32px] font-bold">
    Communication avec pipe nommé (FIFO)
  </h1>
  <div class="w-full flex items-center justify-center gap-6 px-4">
    <!-- PROCESSUS A -->
    <div class="flex flex-col items-center">
      <div class="w-40 h-24 border-4 border-blue-500 bg-blue-50 rounded-lg flex flex-col items-center justify-center shadow-md">
        <span class="text-xl font-bold text-blue-900">Processus A</span>
        <span class="text-sm font-mono text-blue-800 mt-1">Écrivain</span>
      </div>
    </div>
    <!-- ARROW 1 -->
    <div class="w-16 flex items-center justify-center text-gray-700">
      <div class="h-1 w-full bg-gray-700"></div>
      <div class="w-0 h-0 border-t-[6px] border-t-transparent border-l-[12px] border-l-gray-700 border-b-[6px] border-b-transparent"></div>
    </div>
    <!-- FIFO / FICHIER -->
    <div class="flex flex-col items-center gap-1 -mt-4">
      <div class="text-sm font-bold mb-1">
        /tmp/my_fifo
      </div>
      <div class="w-32 h-20 border-4 border-gray-500 bg-gray-100 rounded-lg flex items-center justify-center shadow-inner relative overflow-hidden">
         <span class="text-lg font-bold text-gray-700 z-10 bg-gray-100 px-2 rounded">FIFO</span>
         <div class="absolute inset-0 opacity-10 bg-[repeating-linear-gradient(90deg,transparent,transparent_10px,#000_10px,#000_12px)]"></div>
      </div>
    </div>
    <!-- ARROW 2 -->
    <div class="w-16 flex items-center justify-center text-gray-700">
      <div class="h-1 w-full bg-gray-700"></div>
      <div class="w-0 h-0 border-t-[6px] border-t-transparent border-l-[12px] border-l-gray-700 border-b-[6px] border-b-transparent"></div>
    </div>
    <!-- PROCESSUS B -->
    <div class="flex flex-col items-center">
      <div class="w-40 h-24 border-4 border-green-500 bg-green-50 rounded-lg flex flex-col items-center justify-center shadow-md">
        <span class="text-xl font-bold text-green-900">Processus B</span>
        <span class="text-sm font-mono text-green-800 mt-1">Lecteur</span>
      </div>
    </div>
  </div>
</div>

---
layout: center
class: text-center
---

# MERCI!
Questions?
