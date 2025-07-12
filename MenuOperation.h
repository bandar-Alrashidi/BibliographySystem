//
// Created by bande on 7/1/2025.
//

#ifndef MENUOPERATION_H
#define MENUOPERATION_H



void createMenu();
void menuHandling(int userChoice);

void searchByAuthor(char *authorName );
int searchByTitle(char *titleName );
void searchByYear(int year);
void searchByRangeYears(int beginning , int ending);
void checkDuplicates();
void displayEntryTypesAndCount();
void showMissingEntries();
void AddNewRecords(char *Type , char *citeKey , char *Author , char *Title , int Year   );
void DisplayAuthorsAlphabetically();
void GenereteHarvardRef(int index);
#endif //MENUOPERATION_H
