#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(){
    printf("Dictionnaire.\n\n");

    char choice;

    while (choice < 49 || choice > 55) {
        printf("1 - Creer un fichier dictionnaire\n");
        printf("2 - Utiliser un dictionnaire existant\n");
        printf("3 - Fabriquer un dictionnaire a partir d'un fichier texte\n");
        printf("4 - Detruire un fichier dictionnaire\n");
        printf("5 - Inserer un mot dans un dictionnaire\n");
        printf("6 - Rechercher un mot dans un dictionnaire\n");
        printf("7 - Quitter\n");

        printf("\nChoix -> ");
        scanf("\n%c", &choice);
    }

    switch (choice) {
        case 49:
            break;
        case 50:
            break;
        case 51:
            break;
        case 52:
            break;
        case 53:
            break;
        case 54:
            break;
        case 55:
            exit(0);
        default:
            break;
    }
}
