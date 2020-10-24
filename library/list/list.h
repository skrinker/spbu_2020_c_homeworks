#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

#ifndef SPBU_2020_C_LIST_H
#define SPBU_2020_C_LIST_H

typedef struct ListElement ListElement;

typedef struct List List;

List* createList();
ListElement* getNext(ListElement* element);
bool isEmpty(List* list);
ListElement* createListElement(int value);
ListElement* createListElementWithNext(int value, ListElement* next);
ListElement* tail(List* list);
ListElement* head(List* list);
bool insert(ListElement* element, int position, List* list);
int locate(ListElement* element, List* list);
ListElement* retrieve(int position, List* list);
bool deleteElement(int position, List* list);
void printList(List* list);
int getSize(List* list);
int getValue(ListElement* element);
void deleteList(List* list);
void updateNext(ListElement* element, ListElement* next);
void updateHead(List* list, ListElement* element);
void changeSize(int step, List* list);
ListElement* getNextElementInCycle(ListElement* element, List* list);

#endif
