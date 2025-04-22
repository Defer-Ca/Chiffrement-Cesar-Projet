#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Cesar.h"


bool verifAlphaNum(char *str){ //verifie si il a y des caractères spéciaux dans str et renvoie true si il y en a
    for (int i = 0; i < strlen(str); i++) { //verifie si le charactère n'est PAS entre A et Z ou a et z + compte les espace si c'est une phrase sinon bug
        if (!((str[i] >= 'A' && str[i] <= 'Z') ||
              (str[i] >= 'a' && str[i] <= 'z') ||
              str[i] == ' ')) {
            return true;
        }
    }
    return false;
}




void chiffrer(char *str, int cle){ //chiffre les charactères de str avec un clé fourni
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') { // verifie le cas ou les char donné sont en Majuscule(entre A et Z)
            str[i] = ((str[i] - 'A' + cle) % 26) + 'A'; // str[i]-'A' donne le nombre ou est placé str[i] dans l'alphabet on ajoute la clé, si superieur a Z, on retourne au nombre de A + le reste, puis ensuite on ajoute 'A' a l'ensemble pour le ramener au code ASCII
        }


        else if (str[i] >= 'a' && str[i] <= 'z') { //verifie le cas ou les char donné sont en Minuscules (entre a et z)
            str[i] = ((str[i] - 'a' + cle) % 26) + 'a';//meme chose mais avec les minuscule
        }
    }
}



void dechiffrer(char *str, int cle){ //dechiffre les charactères de str avec une clé fourni
    for (int i = 0; i < strlen(str); i++) {

        if (str[i] >= 'A' && str[i] <= 'Z') { //meme principe que chiffrer

            if((str[i] - 'A' - cle)<0){ //verifie si on passe en négatif dans l'alphabet(donc un lettre qui n'existe pas)
                int dif= (str[i] - 'A' - cle)+26; //si c'est le cas on revient a Z
                str[i] = dif + 'A'; //et on retire le reste (donc si on arrive a -2, cela fait Z-2 ce qui donne X)
            }else{
                str[i] = (str[i] - 'A' - cle) + 'A'; //sinon on retire juste avec la clé
            }
        }

        else if (str[i] >= 'a' && str[i] <= 'z') { // meme principe que chiffrer
            if((str[i] - 'a' - cle)<0){
                int dif= (str[i] - 'a' - cle)+26;
                str[i] = dif + 'a';                         //meme chose pour tous mais avec les minuscule
            }else{
                str[i] = (str[i] - 'a' - cle) + 'a';
            }
        }
    }
}


void Affichage(char *str){ // Affiche la chaine de caractère donné
    for (int i = 0; i < strlen(str); i++) {
        printf("%c", str[i]);
    } 
    printf("\n");
}



