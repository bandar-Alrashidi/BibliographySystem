//
// Created by bande on 7/1/2025.
//

#ifndef MENUOPERATION_H
#define MENUOPERATION_H



void createMenu();
void menuHandling(int userChoice);

void searchByAuthor(char *authorName );
void searchByTitle(char *titleName );
void searchByYear(int year);
void searchByRangeYears(int beginning , int ending);
void checkDuplicates();
void displayEntryTypesAndCount();
void showMissingEntries();
#endif //MENUOPERATION_H
