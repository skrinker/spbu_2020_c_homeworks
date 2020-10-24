#include "list.h"

struct ListElement {
    int value;
    struct ListElement* next;
};

struct List {
    int size;
    struct ListElement* head;
};

List* createList()
{
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;
    return list;
}

bool isEmpty(List* list)
{
    return (getSize(list) == 0);
}

ListElement* createListElement(int value)
{
    ListElement* listElement = malloc(sizeof(ListElement));
    listElement->value = value;
    listElement->next = NULL;
    return listElement;
}

ListElement* createListElementWithNext(int value, ListElement* next)
{
    ListElement* listElement = malloc(sizeof(ListElement));
    listElement->value = value;
    listElement->next = next;
    return listElement;
}

ListElement* head(List* list)
{
    return list->head;
}

ListElement* tail(List* list)
{
    if (getSize(list) < 1)
        return list->head;
    ListElement* current = list->head;
    while (getNext(current) != NULL) {
        current = getNext(current);
    }
    return current;
}

bool insert(ListElement* element, int position, List* list)
{
    if (position < 0 || position > getSize(list)) {
        return false;
    }
    if (position == 0) {
        ListElement* current = list->head;
        list->head = element;
        element->next = current;
        ++(list->size);
        return true;
    }
    if (position > 0) {

        ListElement* current = list->head->next;
        ListElement* previous = list->head;
        for (int i = 1; i < position; i++) {
            previous = current;
            current = getNext(current);
        }
        previous->next = element;
        element->next = current;
        ++(list->size);
        return true;
    }
}

void printList(List* list)
{
    ListElement* current = list->head;
    for (int i = 0; i < getSize(list) - 1; i++) {
        printf("%d -> ", getValue(current));
        current = getNext(current);
    }
    printf("%d \n", getValue(current));
}

int locate(ListElement* element, List* list)
{
    ListElement* current = list->head;
    int position = 0;
    while (current != NULL) {
        if (getNext(current) == getNext(element) && getValue(current) == getValue(element))
            return position;
        current = getNext(current);
        ++position;
    }
    return -1;
}

int locateByValue(ListElement* element, List* list)
{
    ListElement* current = list->head;
    int position = 0;
    while (current != NULL) {
        if (getValue(current) == getValue(element))
            return position;
        current = getNext(current);
        ++position;
    }
    return -1;
}

ListElement* retrieve(int position, List* list)
{
    if (position < getSize(list)) {
        ListElement* current = list->head;
        for (int i = 0; i < position; i++) {
            current = getNext(current);
        }
        return current;
    }
}

bool deleteElement(int position, List* list)
{
    if (position < 0 || position >= getSize(list)) {
        return false;
    }
    if (position == 0) {
        list->head = getNext(head(list));
        (list->size)--;
        return true;
    }
    if (position > 0) {
        ListElement* current = getNext(head(list));
        ListElement* previous = head(list);
        for (int i = 1; i < position; i++) {
            previous = current;
            current = getNext(current);
        }
        previous->next = getNext(current);
        free(current);
        (list->size)--;

        return true;
    }
}

int getSize(List* list)
{
    return list->size;
}

int getValue(ListElement* element)
{
    return element->value;
}

ListElement* getNext(ListElement* element)
{
    return element->next;
}

bool deleteList(List* list)
{
    ListElement* current = list->head;
    ListElement* previous = NULL;
    while (current != NULL) {
        previous = current;
        current = getNext(current);
        free(previous);
    }
    free(list);
    return true;
}

void updateNext(ListElement* element, ListElement* next)
{
    element->next = next;
}

void updateHead(List* list, ListElement* element)
{
    list->head = element;
}

void changeSize(int step, List* list)
{
    list->size += step;
}

ListElement* getNextElementInCycle(ListElement* element, List* list)
{
    if (element == NULL)
        return NULL;
    ListElement* next = getNext(element);
    if (next == NULL)
        next = head(list);
    return next;
}
