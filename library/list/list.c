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

void push(List* list, int value)
{
    if (isEmpty(list)) {
        list->head = createListElement(value);
    } else {
        ListElement* tailElement = tail(list);
        tailElement->next = createListElement(value);
    }
    list->size++;
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
        free(element);
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
    if (getSize(list) == 0) {
        printf("list is empty \n");
        return;
    }
    ListElement* current = list->head;
    for (int i = 0; i < getSize(list); i++) {
        printf("%d ", getValue(current));
        current = getNext(current);
    }
    printf("\n");
}

int locate(ListElement* element, List* list)
{
    ListElement* current = list->head;
    int position = 0;
    while (current != NULL) {
        if (current == element)
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

int retrieve(int position, List* list)
{
    if (position < getSize(list) && position >= 0) {
        ListElement* current = list->head;
        for (int i = 0; i < position; i++) {
            current = getNext(current);
        }
        return current->value;
    }
    return NULL;
}

bool deleteElement(int position, List* list)
{
    if (position < 0 || position >= getSize(list)) {
        return false;
    }
    if (position == 0) {
        ListElement* current = head(list);
        list->head = getNext(head(list));
        free(current);
        --(list->size);
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
        --(list->size);

        return true;
    }
}

int getSize(List* list)
{
    if (list == NULL) {
        return 0;
    }
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

void deleteList(List* list)
{
    while (!isEmpty(list)) {
        deleteElement(0, list);
    }
    free(list);
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
