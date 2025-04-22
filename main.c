#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Cesar.h"

int main(){
    char mess[100];
    int choix;
    int cle;

    printf("------------- CODE CESAR -------------\n"); //menu
    printf("Choisissez votre option\n");
    printf("1.     Chiffrer\n");
    printf("2.     Déchiffrer\n");
    printf("Autre. Sortir\n");
    scanf("%d", &choix);

    if (!(choix == 1 || choix == 2)) { // Sortir du programme
        return 0;
    }

    printf("Entrez la clé : \n"); //scan de la clé
    scanf("%d", &cle);
    getchar(); //consomme le \n resté dans le buffer 

    printf("Entrez votre message : \n"); //scan du message
    fgets(mess, sizeof(mess), stdin);
    mess[strcspn(mess, "\n")] = 0; // supprime le \n à la fin sinon cela active VerifAlphaNum

    while (verifAlphaNum(mess) == true) { //verification du message
        printf("Le message contient des caractères illégaux, réessayez :\n");
        fgets(mess, sizeof(mess), stdin);
        mess[strcspn(mess, "\n")] = 0;
    }

    if (choix == 1) { //chiffrer
        chiffrer(mess, cle);
        printf("Votre message chiffré est : ");
        Affichage(mess);
    } else if (choix == 2) { //déchiffrer
        dechiffrer(mess, cle);
        printf("Votre message déchiffré est : ");
        Affichage(mess); 
    }


}
