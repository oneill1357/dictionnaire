#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "gestlib.h"


void retryOrExit() {

    char res;
    printf("Revenir au menu ou quitter le programme ? (o poour revenir au menu) : ");
    scanf("%s", &res);
    if(res == 79 || res == 111){
        menu();
    }else{
        exit(0);
    }

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
    }else{
        printf("Nom du fichier dictionnaire a utiliser: ");
    }
    char path[100];
    scanf("%s",&path);
    return loadExistingDictionary(path,mode);

}
//Ouvre et retourne le fichier
FILE* loadExistingDictionary(char * path,char* mode) {

    FILE* file = NULL;

    file = fopen(path,mode);

    if(file == NULL){
       fileNotFound(path);
    }

    return file;
}

void createDictionaryFile() {

    askDictionaryPath(1,"a");
    printf("Le fichier dictionnaire a ete cree !\n");
    retryOrExit();
}

// Ouvre et lit toutes les lignes du fichier
void useExistingDictionary() {

    FILE* file = askDictionaryPath(-1,"r");

    char line[100];
    while(fgets(line, sizeof(line),file)){
        printf("%s",line);
    }

    fclose(file);
    retryOrExit();

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
    remove(path);
    printf("Le dictionnaire a ete supprime\n");

    retryOrExit();
}

// Insert le mot à la fin du dictionnaire
void insertWordDictionary() {

    FILE* file = askDictionaryPath(-1,"a");
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

    FILE* file = askDictionaryPath(-1,"r");

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

void displayListCloseWords(){

//    char line[100];
//    char word[100];
//    int t;
//
//    do {
//        printf("Entrez le mot de proximite : ");
//        scanf("%s", &word);
//        printf("Entrez le seuil de tolerance : ");
//        scanf("%d", &t);
//        if(strlen(word) < t){
//            printf("Le seuil de tolerance est plus grand que le nombre de caractere !\n");
//        }
//    }while(strlen(word) < t);
//
//    printf("Enfin, entrez le ");
//    FILE* file = askDictionaryPath(-1,"r");
//
//    while(fgets(line, sizeof(line), file)) {
//        printf("La difference du dico %s avec %s est de %d\n",line,word,strcmp(word,line));
//        int i = 0;
//        for(; i <strlen(line); i++){
//            line[i]
//        }
//    }
//
//    retryOrExit();

    char * s1= "unestring";
    char * s2 ="unechaine";

    if(strlen(s1) < strlen(s2)){

    }else if(strlen(s1) > strlen(s2)){

    }else{
        int i = 0;
        for(; i <strlen(s1);i++){

        }
    }
}

//A modifier, numéro de ligne non implémenté
void showWordsNotExist(){

    FILE* file = askDictionaryPath(2,"r");
    FILE* dico = askDictionaryPath(-1,"r");
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

void menu() {
    printf("Dictionnaire.\n\n");

    char choice;

    do {
        printf("1 - Creer un fichier dictionnaire\n");
        printf("2 - Utiliser un dictionnaire existant\n");
        printf("3 - Fabriquer un dictionnaire a partir d'un fichier texte\n");
        printf("4 - Detruire un fichier dictionnaire\n");
        printf("5 - Inserer un mot dans un dictionnaire\n");
        printf("6 - Rechercher un mot dans un dictionnaire\n");
        printf("7 - Lister les mots proche (non terminee) \n");
        printf("8 - Afficher les mots qui n'existe pas dans un dictionnaire  (non terminee) \n");
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