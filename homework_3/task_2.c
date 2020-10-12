#include "list.c";

void createCycleList(List* list)
{
    ListElement* tailElement = tail(list);
    tailElement->next = head(list);
}

void deletePeriodicallyInCycleShit(int step, List* list)
{
    int listSize = list->size;
    ListElement* current = list->head->next;
    ListElement* previous = list->head;
    for (int i = 1; i < listSize; i++) {
        for (int j = 1; j < step - 1; j++) {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        if (current->value == list->head->value) {
            list->head = current->next;
        }
        previous = current->next;
        current = current->next->next;
        (list->size)--;
    }
}

int main()
{
    int numberOfWarriors = 0;
    printf("input number of warriors: \n");
    scanf("%d", &numberOfWarriors);
    ListElement** elements = (ListElement**)malloc(numberOfWarriors * sizeof(ListElement));
    List* list = createList();
    for (int i = 0; i < numberOfWarriors; i++) {
        elements[i] = createListElement(i);
        insert(elements[i], i, list);
    }

    createCycleList(list);

    int killedWarrior = 0;
    printf("who are we killing? \n");
    scanf("%d", &killedWarrior);

    deletePeriodicallyInCycleShit(killedWarrior, list);

    printf("last warrior: ");
    printf("%d\n", list->head->value);

    for (int i = 0; i < numberOfWarriors; i++)
        free(elements[i]);
    free(list);
    free(elements);

    return 0;
}