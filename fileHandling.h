//
// Created by bande on 7/1/2025.
//

#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#define max_records 100
#define max_fields 250

typedef struct
{
    char titles [max_fields];
    char types  [max_fields];
    char authors  [max_fields];
    int year ;
}Records;

void cleanField(char *str);
int readData(char * location );
void printData();
#endif //FILEHANDLING_H
