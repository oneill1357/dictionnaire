#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestlib.h"
#include "gestrech.c"
#include "gestorth.c"

char dico[128];

void retryOrExit() {

        int exitDo = 0;
        do{
            char res;
            printf("Revenir au menu ou quitter le programme ? (o poour revenir au menu) : ");
            scanf("%s", &res);
            if(res == 79 || res == 111){
                    menu();
                exitDo =1;
                }else if( res == 78 || res == 110){
                    exit(0);
                }else{
                    printf("(Oo) pour continuer ou (Nn) pour quitter\n");
                }

        }while(!exitDo);

}
void fileNotFound(char * path) {
    printf("Impossible de charger le fichier. (%s).  \n", path);
    retryOrExit();
}

FILE* askDictionaryPath(int num,char * mode) {

    if(num == 1){
        printf("Nom du fichier dictionnaire a creer : ");
    }else if(num == 2){
        printf("Nom du fichier texte a scanner : ");
    }else if(num == 3){
        printf("Nom du dictionnaire a remplir : ");
    }else if(num == 4){
        printf("Nom du fichier dictionnaire a charger: ");
    }else{
        printf("Nom du fichier dictionnaire a utiliser: ");
    }
    char path[100];
    scanf("%s",&path);
    if(num == 4){
        dico[0] = 0;
        strcat(dico,path);
    }
    return loadNewFile(path,mode,num);

}
//Ouvre et retourne le fichier
FILE* loadNewFile(char * path,char* mode,int num) {

    FILE* file = NULL;

    file = fopen(path,mode);

    if(file == NULL){
        if(num == 4){
            dico[0] = 0;
        }
       fileNotFound(path);
    }

    return file;
}
FILE* loadExistingFile(char * mode){

    if(strlen(dico) != 0){
        FILE* file = fopen(dico,mode);
        if(file != NULL){
            return file;
        }else{
            printf("Impossible de charger le fichier\n");
            retryOrExit();
        }

    }else{
        printf("Le chemin du fichier n'est pas defini\n");
        retryOrExit();
    }
}

void createDictionaryFile() {

    askDictionaryPath(1,"a");
    printf("Le fichier dictionnaire a ete cree !\n");
    retryOrExit();
}

// Ouvre et lit toutes les lignes du fichier
void useExistingDictionary() {

    FILE* file = askDictionaryPath(4,"r");

    char line[100];
    int exitDo = 0;
    int inspect = 0;
    do{
        char res;
        printf("Voulez-vous inspecter le fichier ? (o/n)");
        scanf("%s", &res);
        if(res == 79 || res == 111){
            inspect = 1;
            exitDo =1;
        }else if( res == 78 || res == 110){
            fclose(file);
            menu();
        }else{
            printf("(Oo) pour lister , (Nn) pour revenir au menu\n");
        }

    }while(!exitDo);

    if(inspect == 1) {
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
    }
    printf("------ Fin du fichier ------\n");

    fclose(file);
    menu();

}

// A modifier
void buildDictionaryWithTxt() {

    FILE* txt = askDictionaryPath(2,"r");
    FILE* dico = askDictionaryPath(3,"a");
    int c;

    printf("Traitement en cours...\n");
    while ((c = fgetc(txt)) != EOF) {
        if(c == 32){
            fputc('\n',dico);
        }else{
            fputc(c,dico);
        }
    }
    fclose(txt);
    fclose(dico);
    printf("Le dictionnaire a ete construit\n");
    retryOrExit();
}
// Supprime un dictionnaire
void deleteDictionaryFile() {
    char path[100];
    printf("Nom du fichier dictionnaire a supprimer : ");
    scanf("%s",&path);
    if(strcmp(path,dico) == 0){
        dico[0] = 0;
    }
    remove(path);
    printf("Le dictionnaire a ete supprime\n");

    retryOrExit();
}

// Insert le mot à la fin du dictionnaire
void insertWordDictionary() {

    FILE* file = loadExistingFile("a");
    char word[128];
    printf("Entrez le mot a rajouter au dictionnaire : ");
    scanf("%s", &word);

    fprintf(file,"%s\n",word);

    fclose(file);
    printf("%s a ete rajoute au dictionnaire\n",word);

    retryOrExit();
}

// Recherche un mot dans le dictionnaire
void searchWordDictionary() {

    FILE* file = loadExistingFile("r");

    char word[100];
    char line[100];
    int res = 0;

    printf("Entrez le mot que vous voulez rechercher : ");
    scanf("%s", &word);

    printf("Recherche en cours...\n");
    while(fgets(line, sizeof(line), file)) {
        if(strstr(line,word)) {
            printf("Le mot '%s' se trouve dans le dictionnaire !\n",word);
            res = 1;
            break;
        }
    }
    fclose(file);

    if(!res){
        printf("Le mot '%s' n'existe pas dans le dictionnaire.\n",word);
    }

    retryOrExit();

}

void menu() {
    printf("Dictionnaire.\n\n");

    char choice;

    do {
        if(strlen(dico) == 0){
            printf("!! Aucun dictionnaire defini !!\n");
        }else{
            printf("Le dictionnaire defini est %s\n",dico);
        }
        printf("1 - Creer un fichier dictionnaire\n");
        printf("2 - Utiliser un dictionnaire existant\n");
        printf("3 - Fabriquer un dictionnaire a partir d'un fichier texte\n");
        printf("4 - Detruire un fichier dictionnaire\n");
        printf("5 - Inserer un mot dans un dictionnaire\n");
        printf("6 - Rechercher un mot dans un dictionnaire\n");
        printf("7 - Lister les mots proche (non terminee) \n");
        printf("8 - Afficher les mots qui n'existe pas dans un dictionnaire\n");
        printf("9 - Quitter\n");

        printf("\nChoix -> ");
        scanf("\n%c", &choice);
    }while (choice < 49 || choice > 57);

    switch (choice) {
        case 49:
            createDictionaryFile();
            break;
        case 50:
            useExistingDictionary();
            break;
        case 51:
            buildDictionaryWithTxt();
            break;
        case 52:
            deleteDictionaryFile();
            break;
        case 53:
            insertWordDictionary();
            break;
        case 54:
            searchWordDictionary();
            break;
        case 55:
            displayListCloseWords();
            break;
        case 56:
            showWordsNotExist();
        case 57:
            exit(0);
        default:
            break;

    }
}