#include "list.h"

struct ListElement {
    int value;
    ListElement* next;
    ListElement* previous;
};

struct List {
    int size;
    ListElement* head;
    ListElement* tail;
};

List* createList()
{
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;
    list->tail = NULL;
    return list;
}

ListElement* createListElement(int value)
{
    ListElement* listElement = malloc(sizeof(ListElement));
    listElement->value = value;
    listElement->next = NULL;
    listElement->previous = NULL;
    return listElement;
}

ListElement* head(List* list)
{
    return list->head;
}

ListElement* tail(List* list)
{
    return list->tail;
}

bool insert(int value, int position, List* list)
{
    if (position < 0 || position > list->size) {
        return false;
    }
    ListElement* listElement = createListElement(value);
    if (position == 0) {
        if (list->size == 0) {
            list->tail = listElement;
            list->head = listElement;
            list->size = 1;
        } else {
            ListElement* current = list->head;
            list->head = listElement;
            listElement->next = current;
            current->previous = listElement;
            (list->size)++;
        }
        return true;
    }
    if (position == list->size) {
        ListElement* previousTail = list->tail;
        previousTail->next = listElement;
        listElement->previous = previousTail;
        list->tail = listElement;
        (list->size)++;
        return true;
    }
    if (position > 0) {

        ListElement* current = list->head->next;
        ListElement* previous = list->head;
        for (int i = 1; i < position; i++) {
            previous = current;
            current = current->next;
        }
        previous->next = listElement;
        listElement->next = current;
        (list->size)++;
        return true;
    }
}

bool isSymmetric(List* list)
{
    ListElement* head = list->head;
    ListElement* tail = list->tail;
    int index = 0;
    while (index < list->size / 2) {
        if (head->value != tail->value)
            return false;
        head = head->next;
        tail = tail->previous;
        index++;
    }
    return true;
}

void printList(List* list)
{
    ListElement* current = list->head;
    for (int i = 0; i < list->size - 1; i++) {
        printf("%d <-> ", current->value);
        current = current->next;
    }
    printf("%d", current->value);
    printf("\n");
}
