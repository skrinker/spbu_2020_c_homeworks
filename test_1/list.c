#include "list.h"

List* createList()
{
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;
    return list;
}

bool isEmpty(List* list)
{
    return (list->size == 0);
}

ListElement* createListElement(int value)
{
    ListElement* listElement = malloc(sizeof(ListElement));
    listElement->value = value;
    listElement->next = NULL;
    return listElement;
}

ListElement* head(List* list)
{
    return list->head;
}

ListElement* tail(List* list)
{
    if (list->size < 1)
        return list->head;
    ListElement* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    return current;
}

bool insert(ListElement* listElement, int position, List* list)
{
    if (position < 0 || position > list->size) {
        return false;
    }
    if (position == 0) {
        ListElement* current = list->head;
        list->head = listElement;
        listElement->next = current;
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

void printList(List* list)
{
    ListElement* current = list->head;
    for (int i = 0; i < list->size; i++) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("\n");
}

int locate(ListElement* listElement, List* list)
{
    ListElement* current = list->head;
    int index = 0;
    while (current != NULL) {
        if (current->value == listElement->value) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

ListElement* retrieve(int position, List* list)
{
    if (position < list->size) {
        ListElement* current = list->head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
        return current;
    }
}

bool deleteElement(int position, List* list)
{
    if (position < 0 || position > list->size) {
        return false;
    }
    if (position == 0) {
        list->head = list->head->next;
        (list->size)--;
        return true;
    }
    if (position > 0) {
        ListElement* current = list->head->next;
        ListElement* previous = list->head;
        for (int i = 1; i < position; i++) {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        (list->size)--;

        return true;
    }
}

void push(int value, List* list)
{
    ListElement* listElement = createListElement(value);
    if (list->size == 0) {
        list->head = listElement;
        (list->size)++;
    } else {
        ListElement* current = list->head->next;
        ListElement* previous = list->head;
        while (current != NULL) {
            previous = current;
            current = current->next;
        }
        previous->next = listElement;
        listElement->next = current;
        (list->size)++;
    }
    free(listElement);
}

void sortedMerge(List* list1, List* list2, List* result)
{
    ListElement* current1 = head(list1);
    ListElement* current2 = head(list2);

    while (current1 != NULL || current2 != NULL) {
        if (current1 == NULL) {
            push(current2->value, result);
            continue;
        } else if (current2 == NULL) {
            push(current1->value, result);
            continue;
        }

        if (current1->value < current2->value) {
            push(current1->value, result);
            current1 = current1->next;
        } else {
            push(current2->value, result);
            current2 = current2->next;
        }
    }
}
