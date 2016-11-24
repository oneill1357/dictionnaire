#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(){
    printf("Dictionnaire.\n\n");

    int choice = 0;

    while (choice <= 0 || choice > 7) {
        printf("1 - Creer un fichier dictionnaire\n");
        printf("2 - Utiliser un dictionnaire existant\n");
        printf("3 - Fabriquer un dictionnaire a partir d'un fichier texte\n");
        printf("4 - Détruire un fichier dictionnaire\n");
        printf("5 - Inserer un mot dans un dictionnaire\n");
        printf("6 - Rechercher un mot dans un dictionnaire\n");
        printf("7 - Quitter\n");

        printf("\nChoix -> ");
        scanf("\n%[^\n]", &choice);
    }

    switch (choice) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            exit(0);
            break;
        default:
            break;
    }
}
