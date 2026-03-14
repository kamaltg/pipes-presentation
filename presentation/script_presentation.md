# Script de Présentation : IPC et Les Tubes (Pipes) en C

## Slide 1 : Page de garde
"Bonjour à toutes et à tous. Je vous présente aujourd'hui mon travail à faire (TAF) sur les mécanismes de communication interprocessus, et plus spécifiquement les tubes (pipes). Ce travail a été réalisé par moi-même, Kamal Taghlaoui, sous l'encadrement du Professeur Abdellah Ouaguid."

## Slide 2 : Le Contexte
"Pour commencer, définissons le contexte. La communication interprocessus, ou IPC, regroupe un ensemble de mécanismes qui permettent à plusieurs processus de communiquer et de se synchroniser. Il est important de noter que ces mécanismes suivent des interfaces standardisées, notamment selon le standard POSIX pour les systèmes de type Unix."

## Slide 3 : Les mécanismes de communication (IPC)
*(Cliquer pour faire apparaître chaque encadré petit à petit)*
"Il existe plusieurs mécanismes d'IPC :
1. **Les Tubes (pipes)** : Permettent une communication unidirectionnelle entre processus apparentés.
2. **Les Files de messages** : Permettent d'échanger des paquets de données via une file d'attente.
3. **Les Signaux** : Utilisés pour notifier asynchronement un processus qu'un événement s'est produit.
4. **Les Sockets** : Utilisés pour la communication à travers un réseau ou localement.
5. **La Mémoire partagée** : Le moyen de communication le plus rapide, où plusieurs processus accèdent directement à une même zone de la RAM.
6. **Les Fichiers mappés** : Permettent de manipuler le contenu d'un fichier directement en mémoire centrale."

## Slide 4 : Méthode de tubes (Pipes) - Code de base
"Voici le programme d'introduction sur lequel nous allons travailler. Ce programme C simple tente d'implémenter une communication entre un processus père et son fils à l'aide de la fonction `pipe()`. Cependant, ce code est naïf : il présente plusieurs lacunes et oublie de nombreuses bonnes pratiques de la programmation système."

## Slide 5 : Travail demandé
"Le travail demandé pour cet exercice consiste à :
- Proposer une version corrigée et propre.
- Vérifier systématiquement les retours des appels système comme `pipe()`, `fork()`, `read` et `write`.
- Ajouter les tests d'erreurs nécessaires pour gérer et identifier les défaillances.
- Améliorer la lisibilité du code avec un bon nommage de variables.
- Ajouter des commentaires explicatifs pour chaque grande étape."

## Slide 6 : Objectif
"L'objectif de ce programme corrigé est de permettre de manière robuste : 
Au processus fils d'écrire un message (comme 'bonjour') dans le tube.
Puis au processus père de lire ce message depuis de ce tube et de l'afficher sur la console."

## Slide 7 : Code initial (rappel)
"Revenons brièvement sur le code initial. On remarque l'absence totale de `perror()`, l'utilisation non justifiée d'un `else if (f > 0)` sans `wait()`, et le fait que les extrémités du pipe ne sont jamais fermées après utilisation."

## Slide 8 : 1ère étape de correction - Déclarations et Inclusions
"La première étape de notre correction consiste à importer les bibliothèques adéquates, notamment `<sys/wait.h>` et `<unistd.h>`. 
*(Animation magic-move : passer à la suite)*
Nous déclarons ensuite nos variables de manière descriptive : un descripteur `d[2]`, `pid_child` pour le fork, `message_received` comme buffer, et `stat` pour récupérer le code de retour du processus fils."

## Slide 9 : Tests d'erreurs Pipe et Fork
*(Animation magic-move)*
"Ensuite, nous intégrons les vérifications d'erreur. La création du pipe et le fork peuvent tous les deux échouer. Si la valeur retournée est inférieure à 0, on affiche un message clair grâce à `perror()` et on quitte le programme avec `exit(EXIT_FAILURE)`."

## Slide 10 : Logique du processus fils
*(Animation magic-move)*
"Examinons la logique du fils. 
- Puisque le fils ne fait qu'écrire, il est impératif qu'il **ferme l'extrémité de lecture** `d[0]`.
- Il écrit son message avec `write()` dans `d[1]`. On gère également l'erreur potentielle de cette écriture.
- Une fois terminé, il ferme son extrémité d'écriture `d[1]` pour indiquer la fin des données, et s'arrête avec un succès."

## Slide 11 & 12 : Logique du processus père
*(Animation magic-move)*
"Du côté du père maintenant, voici comment cela fonctionne.
- Le père agit en tant que lecteur. Il doit donc **fermer son extrémité d'écriture** `d[1]`.
- Il effectue un `read()` depuis `d[0]`.
- Très important : on ajoute manuellement le caractère `\0` à la fin de notre buffer lu, pour garantir que l'affichage par `printf` fonctionnera comme sur une chaîne de caractères valide.
- Le père ferme `d[0]` car la lecture est terminée.
- Enfin, il appelle `wait(&stat)` pour s'assurer que le fils a bien terminé son exécution sans laisser de processus zombie, et on peut afficher son code de retour."

## Slide 13 : Version finale
"Nous obtenons finalement ce code complet. C'est un code robuste. Chaque appel système critique est sécurisé, et chaque extrémité de pipe non pertinente pour le processus courant est fermée juste après le fork. Cela évite les blocages lors de la lecture."

## Slide 14 : Message de n'importe quelle taille ?
"Maintenant, que se passe-t-il si la taille du message est inconnue par le lecteur ou variable ?
*(Animation)*
Dans ce cas, voici le protocole : L'écrivain commence par envoyer un premier message ou bloc qui contient seulement la **taille** de la donnée *(Etape 1)*. Le lecteur lit cette taille, effectue une allocation dynamique avec `malloc()`, puis l'écrivain envoie finalement le **vrai message** de la bonne taille *(Etape 2)*."

## Slide 15 : Communication bidirectionnelle avec 2 pipes
"Le pipe est unidirectionnel (half-duplex). Si le père et le fils doivent avoir un dialogue constant (par exemple, des questions/réponses), comment faire ?
La solution est d'utiliser **deux pipes distincts** : l'un servira au père pour envoyer vers le fils (Pipe 1) et l'autre servira au fils pour répondre au père (Pipe 2)."

## Slide 16 : Communication avec pipe nommé (FIFO)
"Dans notre exemple, on parle de tubes anonymes, qui nécessitent une filiation stricte (père/fils). Mais si deux processus n'ont aucun lien de parenté, comment font-ils pour échanger des données ?
Ils utilisent un **pipe nommé**, aussi appelé FIFO. Contrairement aux pipes anonymes, le FIFO apparait dans le système de fichier (par exemple sous `/tmp/my_fifo`). N'importe quel processus A ou B peut ouvrir ce fichier spécial et communiquer facilement en lecture ou écriture."

## Slide 17 : Merci !
"C'est ce qui conclut ma présentation sur la communication interprocessus via les tubes. Je vous remercie pour votre attention. Si vous avez des questions, c'est à vous !"
