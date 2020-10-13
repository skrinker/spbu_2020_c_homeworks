#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct ListElement {
    int value;
    struct ListElement* next;
} ListElement;

typedef struct List {
    int size;
    struct ListElement* head;
} List;

List* createList();
bool isEmpty(List* list);
ListElement* createListElement(int value);
ListElement* tail(List* list);
ListElement* head(List* list);
bool insert(ListElement* value, int position, List* list);
int locate(ListElement* value, List* list);
ListElement* retrieve(int position, List* list);
bool deleteElement(int position, List* list);
void printList(List* list);
void push(int value, List* list);
void sortedMerge(List* list1, List* list2, List* result);