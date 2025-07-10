#include <stdio.h>
#include <string.h>

#include "MenuOperation.h"
#include "fileHandling.h"
int main(void)
{
    printf("This is my Bibliography project!\n");
    //read date from file
    readData("data.txt");
    checkDuplicates();
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
        int year;
        printf( "Enter Year : \n");
        scanf("%d", &year);
        searchByYear(year);

    }
    else if (userChoice==4)
    {
        int beginning_year , ending_year;
        printf("Enter beginning  year \n");
        scanf("%d", &beginning_year);
        printf("Enter ending  year \n");
        scanf("%d", &ending_year);
       searchByRangeYears(beginning_year, ending_year);

    }
    else if (userChoice==5)
    {

     displayEntryTypesAndCount();

    }
    else if (userChoice==6)
    {

    }
    else if (userChoice==7)
    {
        checkDuplicates();
    }
    else if (userChoice==9)
    {
        showMissingEntries();
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
            printf("Title is : %s \n",records[i].titles);
            printf("Type is : %s \n",records[i].types);
            printf("Year is : %d \n",records[i].year);
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
            printf("Author is : %s \n",records[i].authors);
            printf("Title is : %s \n",records[i].titles);
            printf("Type is : %s \n",records[i].types);
            printf("Year is : %d \n",records[i].year);
        }
    }
}
void searchByYear( int year)
{
    for (int i = 0 ; i<entryCount ; i++)
    {
        if (records[i].year == year )
        {
            printf("Year %d found in record %d\n", year, i+1);
            printf("Author is : %s \n",records[i].authors);
            printf("Title is : %s \n",records[i].titles);
            printf("Type is : %s \n",records[i].types);
            printf("Year is : %d \n",records[i].year);
            printf("---------------------------------------------\n");
        }
    }

}
void searchByRangeYears(int beginning , int ending)
{

    for (int i = 0 ; i<entryCount ; i++)
    {
        if (records[i].year >= beginning && records[i].year <= ending )
        {
            printf("Range Years %d - %d found in record %d\n", beginning ,ending, i+1);
            printf("Author is : %s \n",records[i].authors);
            printf("Title is : %s \n",records[i].titles);
            printf("Type is : %s \n",records[i].types);
            printf("Year is : %d \n",records[i].year);
            printf("---------------------------------------------\n");
        }
    }
}
void checkDuplicates()
{
    int duplicateFound=0;
    for (int outer = 0 ; outer < entryCount-1 ;outer++)
    {
        for ( int inner=outer+1 ; inner<entryCount ;inner++ )
        {
            if (strcmp(records[inner].authors , records[outer].authors)==0 &&
                strcmp(records[inner].titles , records[outer].titles)==0 )
            {
                printf("Duplicate has been found for title %s \n" ,records[inner].titles );
                duplicateFound=1;
            }
        }
    }
    if (duplicateFound==0 )
    {
        printf("No duplicates found \n");
    }
}

void displayEntryTypesAndCount()
{
    char entryType[max_records][max_fields];

    int entryTypes_count[max_records]={0};

    for (int i = 0 ; i<entryCount ; i++)
    {
        int found = 0;
        for (int j=0 ; j <entryCount ; j++)
        {
            if ( strcmp(records[i].types , entryType[j]) ==0 )
            {
                found=1;
                entryTypes_count[j]++;
                break;
            }
        }
        if (found==0)
        {
            strcpy(entryType[i],records[i].types);
            entryTypes_count[i]++;
        }
    }
    for (int i=0 ; i<entryCount ; i++)
    {
        if (entryTypes_count[i]!=0)
             printf(" %s : %d \n",entryType[i] , entryTypes_count[i]);
    }

}

void showMissingEntries()
{

    for (int i=0 ; i<entryCount ; i++)
    {
        int missingFound=0;
        if (strcmp(records[i].authors ,"")==0)
        {
               missingFound=1;
        }
        if (strcmp(records[i].titles ,"")==0)
        {
              missingFound=1;
        }
        if (records[i].year ==0)
        {
            missingFound=1;
        }
        if (missingFound==1)
        {
           printf("Missing found at index  %d \n",i);

        }
    }
}