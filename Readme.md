#  Projet - Chiffrement César en C

##  Objectif

Ce projet est une application en langage C qui permet de **chiffrer** ou **déchiffrer** un message texte à l'aide du **chiffrement de César**, une méthode de cryptographie basée sur le décalage des lettres de l'alphabet.

Ce programme a été réalisé dans le cadre d'un projet scolaire.

**Auteur :** Paul Barse et Soren Pigeau


##  Utilisation
Utiliser "make all" pour compiler le projet
Puis rentrer ./main

L'utilisateur choisit une des options suivantes :
-Chiffrer
-Déchiffrer
-Sortir

Puis il entre :
- Une **clé** entière (positive ou négative)
- Un **message texte** (lettres uniquement, espaces autorisés)

---

##  Documentation des Fonctions

### `bool verifAlphaNum(char *str)`
- **But :** Vérifie si une chaîne contient des caractères non autorisés.
- **Entrée :** `str` (chaîne de caractères)
- **Sortie :** `true` si un caractère non alphabétique (hors espace) est trouvé, sinon `false`.

### `void chiffrer(char *str, int cle)`
- **But :** Chiffre le message donné avec la clé en décalant les lettres.
- **Entrées :**
  - `str` : le message original (modifié directement)
  - `cle` : la clé de chiffrement (int)
- **Sortie :** Aucune (modification en place de `str`)

### `void dechiffrer(char *str, int cle)`
- **But :** Déchiffre un message en appliquant l’inverse de la fonction chiffrer 
- **Entrées :**
  - `str` : le message chiffré (modifié directement)
  - `cle` : la clé utilisée pour le déchiffrement
- **Sortie :** Aucune (modification en place de `str`)

### `void Affichage(char *str)`
- **But :** Affiche une chaîne de caractères caractère par caractère.
- **Entrée :** `str` : chaîne à afficher
- **Sortie :** Aucune

---

##  Gestion des erreurs

- Si l'utilisateur entre un caractère non alphabétique ou un symbole, le programme lui redemande de saisir un message valide.
- Les chiffres et les caractères spéciaux sont refusé.
- L'utilisateur peut quitter le programme en entrant une option autre que 1 ou 2.

---

##  Fichiers

- `main.c` : fichier principale pour le programme
- `Cesar.c / Cesar.h` : fonctions de chiffrement, déchiffrement et vérification