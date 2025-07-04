#include <stdio.h>
#include "MenuOperation.h"
#include "fileHandling.h"
int main(void)
{
    printf("This is my Bibliography project!\n");
    //read date from file
    readData("data.txt");
    printData();
    createMenu();
    return 0;
}


void createMenu()
{
    int userEntry;
    printf("1- Search by Title \n");
    printf("2- Search by Author \n");
    printf("3- Search by Type \n");
    printf("4- Search by Year \n");
    printf("5- Search by range of years \n");

    scanf("%d" , &userEntry);

}

void searchByTitle()
{

}
//
void searchByAuthor()
{

}
