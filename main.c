#include <stdio.h>
#include <string.h>

#include "MenuOperation.h"
#include "fileHandling.h"
int main(void)
{
    printf("This is my Bibliography project!\n");
    //read date from file
    readData("data.txt");
    createMenu();
    return 0;
}


void createMenu()
{
    int choice;
    printf("1- Search by Author \n");
    printf("2- Search by Title \n");
    printf("3- Search by year \n");
    printf("4- Search by range Year \n");
    printf("5- Get Record types and counts \n");
    printf("6- Arrange authors alphabetcally  \n");
    printf("7- Detect duplicates \n");
    printf("8- Display Uwe harvard reference \n");
    printf("9- Show missing info in entries \n");
    printf("10- Add new Entry\n");
    printf("---------------------------------\n");
    printf("Enter from above list please\n");
    scanf("%d" , &choice);

    menuHandling(choice);
}

void menuHandling(int userChoice)
{
    if (userChoice==1) // search by author name
    {
        char authorName[100];
        printf("Enter Author name  : \n");
        scanf("%s", authorName);
        searchByAuthor(authorName);
    }
    else if (userChoice==2)
    {
        char title[100];
        printf( "Enter Title : \n");
        scanf("%s", title);
        searchByTitle(title);
    }
    else if (userChoice==3)
    {

    }
    else if (userChoice==4)
    {

    }
    else if (userChoice==5)
    {

    }
    else if (userChoice==6)
    {

    }
    else if (userChoice==7)
    {

    }
    else if (userChoice==9)
    {

    }
    else if (userChoice==10)
    {

    }

    else
    {
        printf("Wrong choice please choose from 1 to 10\n");
    }
}

void searchByAuthor(char *authorName )
{
    for ( int i = 0 ; i<entryCount ; i++)
    {
        if ( strstr (records[i].authors , authorName))
        {
            printf("Author %s found in record %d\n", authorName, i+1);
            printf("Title is : %s \n",records->titles);
            printf("Type is : %s \n",records->types);
            printf("Year is : %d \n",records->year);
        }
    }
}

void searchByTitle(char *titleName )
{
    for ( int i = 0 ; i<entryCount ; i++)
    {
        if ( strstr (records[i].titles , titleName))
        {
            printf("Title %s found in record %d\n", titleName, i+1);
            printf("Author is : %s \n",records->authors);
            printf("Title is : %s \n",records->titles);
            printf("Type is : %s \n",records->types);
            printf("Year is : %d \n",records->year);
        }
    }
}

