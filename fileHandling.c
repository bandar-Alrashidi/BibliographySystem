//
// Created by bande on 7/1/2025.
#include "fileHandling.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Records records[max_records];;
 int entryCount=0;
int readData(char * filename)
    {

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    char line[1024];
    entryCount = -1;

    while (fgets(line, sizeof(line), fp)) {
        if (line[0] == '@') {
            entryCount++;
            sscanf(line, "@%[^'{']", records[entryCount].types);
        } else if (strstr(line, "title")) {
            char *start = strchr(line, '{');
            if (start) {
                start++;
                strncpy(records[entryCount].titles, start, max_fields - 1);
                cleanField(records[entryCount].titles);
            }
        } else if (strstr(line, "author")) {
            char *start = strchr(line, '{');
            if (start) {
                start++;
                strncpy(records[entryCount].authors, start, max_fields - 1);
                cleanField(records[entryCount].authors);
            }
        } else if (strstr(line, "year")) {
            char *start = strchr(line, '{');
            if (start) {
                records[entryCount].year = atoi(start + 1);
            }
        }
    }

    fclose(fp);
    printf("Loaded %d entries from %s\n", entryCount + 1, filename);
    }

void cleanField(char *str) {
    char *end;
    while (*str == ' ' || *str == '\t') str++;
    end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == ',' || *end == '}')) *end-- = '\0';
    memmove(str, str, strlen(str) + 1);
}
void printData()
{
    for (int i = 0; i < entryCount; i++)
    {
        printf("%s %s %s %d\n", records[i].types, records[i].titles , records[i].authors , records[i].year);
    }
}

//
