#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void fileNotFound(char * path){
    printf("Le fichier n'a pas pu etre ouvert. (%s).  \n", path);
    system("Pause");
    menu();
}

//Ouvre et retourne le fichier
FILE* loadExistingDictionary(char * path,char* mode){

    FILE* file = NULL;

    file = fopen(path,mode);

    if(file == NULL){
       fileNotFound(path);
    }

    return file;
}
// Ouvre et lit toutes les lignes du fichier
void useExistingDictionary(char * path){
    FILE* file = NULL;

    file = fopen(path,"r");

    if(file != NULL) {

        char line[100];
        while(fgets(line, sizeof(line),file)){
            printf("%s",line);
        }

        fclose(file);
        system("pause");
        menu();

    }else{
        fileNotFound(path);
    }

}

// A modifier
void deleteDictionaryFile(){

    menu();
}

// A modifier
void insertWordDictionary(){

    FILE* file = loadExistingDictionary("../dico/dico336k.txt","a");
    char word[128];
    printf("Entrez le mot a rajouter au dictionnaire : ");
    scanf("%s", &word);

    fprintf(file,"%s\n",word);

    fclose(file);
    printf("%s a ete rajoute au dictionnaire\n",word);

    system("pause");
    menu();
}

// A modifier
void searchWordDictionary(){

    FILE* file = loadExistingDictionary("../dico/dico336k.txt","r");

    char line[100];
    while(fgets(line, sizeof(line),file)){
        printf("%s",line);
    }
    fclose(file);

    menu();

}

void menu(){
    printf("Dictionnaire.\n\n");

    char choice;

    do {
        printf("1 - Creer un fichier dictionnaire\n");
        printf("2 - Utiliser un dictionnaire existant\n");
        printf("3 - Fabriquer un dictionnaire a partir d'un fichier texte\n");
        printf("4 - Detruire un fichier dictionnaire\n");
        printf("5 - Inserer un mot dans un dictionnaire\n");
        printf("6 - Rechercher un mot dans un dictionnaire\n");
        printf("7 - Quitter\n");

        printf("\nChoix -> ");
        scanf("\n%c", &choice);
    }while (choice < 49 || choice > 55);

    switch (choice) {
        case 49:
            break;
        case 50:
            useExistingDictionary("../dico/dico336k.txt");
            break;
        case 51:
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
            exit(0);
        default:
            break;

    }
}