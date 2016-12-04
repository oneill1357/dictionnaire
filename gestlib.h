//
// Created by vince on 25/11/2016.
//

#ifndef SOURCES_DICO_GESTLIB_H
#define SOURCES_DICO_GESTLIB_H

void menu();

void fileNotFound(char *);
FILE* loadExistingDictionary(char *,char *);
void useExistingDictionary(char *);
void deleteDictionaryFile();
void insertWordDictionary();
void searchWordDictionary();

#endif //SOURCES_DICO_GESTLIB_H
