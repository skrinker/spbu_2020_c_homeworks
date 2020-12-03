#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct ListElement ListElement;

typedef struct List List;

List* createList();
bool isEmpty(List* list);
ListElement* createListElement(int value);
bool insert(int value, int position, List* list);
void printList(List* list);
bool isSymmetric(List* list);