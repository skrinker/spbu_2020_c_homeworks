#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Date {
    int month;
    int day;
    int year;
} Date;

Date* createDateFromString(char* dataString, char* buffer)
{
    Date* date = malloc(sizeof(Date));
    buffer = strtok(dataString, ".");
    date->day = atoi(buffer);
    buffer = strtok(NULL, ".");
    date->month = atoi(buffer);
    buffer = strtok(NULL, ".");
    date->year = atoi(buffer);
    return date;
}

Date* createDateByValues(int day, int month, int year)
{
    Date* date = malloc(sizeof(Date));
    date->day = day;
    date->month = month;
    date->year = year;
    return date;
}

bool isData(char* str)
{
    if (str == NULL)
        return false;
    return (str[2] == '.' && str[5] == '.');
}

char* getMinimum(Date* data1, Date* data2)
{
    if (data1->year < data2->year)
        return data1;
    else if (data1->year > data2->year)
        return data2;

    if (data1->year == data2->year) {
        if (data1->month < data2->month)
            return data1;
        else if (data1->month > data2->month)
            return data2;
        else if (data1->day < data2->day)
            return data1;
        else if (data1->day > data2->day)
            return data2;
    }
    return data1;
}

int main()
{
    FILE* fp;
    char* buffer = malloc(255 * sizeof(char));
    char* pch;
    char* dataBuffer;
    Date* maxDate = createDateByValues(31, 12, 9999);
    Date* result = createDateByValues(0, 0, 0);
    fp = fopen("/home/skrinker/spbu_2020_c_homeworks/test_2/test.txt", "r");
    while (fgets(buffer, 255, (FILE*)fp) != NULL) {
        pch = strtok(buffer, " ");
        if (isData(pch))
            result = getMinimum(createDateFromString(pch, dataBuffer), maxDate);
        while (pch != NULL) {
            if (isData(pch))
                result = getMinimum(createDateFromString(pch, dataBuffer), maxDate);
            pch = strtok(NULL, " ");
        }
    }
    fclose(fp);

    printf("Minimum date: %d.%d.%d \n", result->day, result->month, result->year);

    free(result);
    free(maxDate);
    free(pch);
    free(dataBuffer);
    free(buffer);

    return 0;
}