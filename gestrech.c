#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void displayListCloseWords() {

    char line[100];
    char word[100];
    int t;

    printf("Entrez le mot de proximite : ");
    scanf("%s", &word);
    printf("Entrez le seuil de tolerance : ");
    scanf("%d", &t);

    printf("Enfin, entrez le ");
    FILE *file = askDictionaryPath(-1, "r");

    while (fgets(line, sizeof(line), file)) {
        if (strspn(line, word) <= (strspn(line, word) - t)) {
            printf("%s", line);
        }
    }

    retryOrExit();
}