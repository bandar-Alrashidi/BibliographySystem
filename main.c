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
    while (1)
         createMenu();
    return 0;
}


void createMenu()
{
    int choice;
    printf("\n\n");
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
    char authorName[100];
    char title[100];
    char type[100];
    char citekey[100];
    int year;
    int beginning_year , ending_year;
    if (userChoice==1) // search by author name
    {

        printf("Enter Author name  : \n");
        scanf("%s", authorName);
        searchByAuthor(authorName);
    }
    else if (userChoice==2)
    {

        printf( "Enter Title : \n");
        scanf("%s", title);
        searchByTitle(title);
    }
    else if (userChoice==3)
    {

        printf( "Enter Year : \n");
        scanf("%d", &year);
        searchByYear(year);

    }
    else if (userChoice==4)
    {

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
        DisplayAuthorsAlphabetically();
    }
    else if (userChoice==7)
    {
        checkDuplicates();
    }
    else if (userChoice==8)
    {
        printf( "Enter Title : \n");
        scanf("%s", title);
        int index = searchByTitle(title);
        GenereteHarvardRef(index);
    }
    else if (userChoice==9)
    {
        showMissingEntries();
    }
    else if (userChoice==10)
    {
        printf("Enter type of entry : \n");
        scanf("%s", type);

        printf( "Enter Cite Key (Optional): \n");
        scanf("%s", citekey);

        printf("Enter Author name  : \n");
        scanf("%s", authorName);

        printf( "Enter Title : \n");
        scanf("%s", title);

        printf( "Enter Year : \n");
        scanf("%d", &year);

        AddNewRecords(type, citekey, authorName, title, year);
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
int searchByTitle(char *titleName )
{
    int index =-1;
    for ( int i = 0 ; i<entryCount ; i++)
    {
        if ( strstr (records[i].titles , titleName))
        {
            printf("Title %s found in record %d\n", titleName, i+1);
            printf("Author is : %s \n",records[i].authors);
            printf("Title is : %s \n",records[i].titles);
            printf("Type is : %s \n",records[i].types);
            printf("Year is : %d \n",records[i].year);
            index = i;
        }
    }
    return index;
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

void AddNewRecords(char *Type , char *citeKey , char *Author , char *Title , int Year )
{
    FILE *fp = fopen("data.txt", "a");
    fprintf(fp, "@%s{%s,\n",Type,citeKey);
    fprintf(fp, "author= {%s},\n",Author);
    fprintf(fp, "title= {%s},\n",Title);
    fprintf(fp, "year= {%d}\n",Year);
    fprintf(fp, "}\n");
    fclose(fp);
}
void DisplayAuthorsAlphabetically()
{
    char tempAuthors[max_records][max_fields];
    int authors_counter=0;

    for ( int i=0 ; i<entryCount ; i++)
    {
        strcpy(tempAuthors[i],records[i].authors);
        authors_counter++;
    }


    for (int i=0 ; i<authors_counter-1 ; i++)
    {
       for ( int j=i+1 ; j <authors_counter ; j++ )
       {
           if ( strcmp (tempAuthors[i] , tempAuthors[j]) > 0 )
           {
               char temp[max_fields];
               strcpy(temp,tempAuthors[i]);
               strcpy(tempAuthors[i],tempAuthors[j]);
               strcpy(tempAuthors[j],temp);
           }
       }
    }
printf("Authors alphabetically\n\n");
    for (int i=0 ; i<authors_counter ; i++)
    {
        printf("%s\n",tempAuthors[i]);
    }
}

void GenereteHarvardRef(int index)
{
    printf("Harvard reference : \n\n");
    printf("%s. ",records[index].authors);
    printf("(%d) ",records[index].year);
    printf("%s",records[index].titles);
}