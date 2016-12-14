//
// Created by vince on 25/11/2016.
//

#ifndef SOURCES_DICO_GESTLIB_H
#define SOURCES_DICO_GESTLIB_H

void menu();

void retryOrExit();
void fileNotFound(char *);
FILE* askDictionaryPath(int,char *);
FILE* loadNewFile(char *,char *,int num);
FILE* loadExistingFile(char * mode);
void createDictionaryFile(); //1
void useExistingDictionary(); //2
void buildDictionaryWithTxt(); //3
void deleteDictionaryFile(); //4
void insertWordDictionary(); //5
void searchWordDictionary(); //6
void displayListCloseWords(); //7
void showWordsNotExist(); // 8

#endif //SOURCES_DICO_GESTLIB_H
