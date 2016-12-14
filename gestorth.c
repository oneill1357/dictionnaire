#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//A modifier, numéro de ligne non implémenté
void showWordsNotExist(){

    FILE* file = askDictionaryPath(2,"r");
    FILE* dico = loadExistingFile("r");
    char dicoWord[64];
    char fileWord[64];

    printf("Fichier ouvert");

    while(!feof(file)){
        rewind(dico);
        int show = 0;
        fscanf(file,"%s ",fileWord);
        int i = 0;
        for(; i < strlen(fileWord);i++){
            fileWord[i] = tolower(fileWord[i]);
        }
        while(!feof(dico)) {
            fscanf(dico, "%s ", dicoWord);
            if(strcmp(fileWord, dicoWord) != 0){
                show = 1;
            }else{
                show = 0;
                break;
            }
        }
        if(show == 1){
            printf("Le mot '%s' n'a pas ete trouve dans le dictionnaire\n",fileWord);
        }
    }
    fclose(file);
    fclose(dico);
    retryOrExit();

}