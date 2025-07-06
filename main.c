#include <stdio.h>
#include "MenuOperation.h"
#include "fileHandling.h"
int entryCount;//store entries count
int main(void)
{
    printf("This is my Bibliography project!\n");
    //read date from file
    entryCount=readData("data.txt");
   // printData();
    createMenu();
    return 0;
}


void createMenu()
{
    int userEntry;
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
    scanf("%d" , &userEntry);

    menuHandling(userEntry);
}

void menuHandling(int userChoice)
{
    if (userChoice==1)
    {
        char authorName[100];
       printf("Enter Author name  : \n");

    }
    else if (userChoice==2)
    {

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

