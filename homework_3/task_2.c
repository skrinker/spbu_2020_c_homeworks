#include "../library/list/list.h"

void deletePeriodicallyInList(int step, List* list)
{
    int listSize = getSize(list);
    ListElement* current = getNext(head(list));
    ListElement* previous = head(list);
    while (getSize(list) > 1) {
        for (int i = 0; i < step - 1; ++i)
            previous = getNextElementInCycle(previous, list);

        int position = locate(previous, list);
        previous = getNextElementInCycle(previous, list);
        deleteElement(position, list);
    }
}

int main()
{
    int numberOfWarriors = 0;
    printf("input number of warriors: \n");
    scanf("%d", &numberOfWarriors);
    ListElement** elements = (ListElement**)malloc(numberOfWarriors * sizeof(ListElement*));
    for (int i = 0; i < numberOfWarriors; i++) {
        elements[i] = NULL;
    }
    List* list = createList();
    for (int i = 1; i <= numberOfWarriors; i++) {
        elements[i - 1] = createListElement(i);
        insert(elements[i - 1], i - 1, list);
    }

    int killedWarrior = 0;
    printf("who are we killing? \n");
    scanf("%d", &killedWarrior);

    deletePeriodicallyInList(killedWarrior, list);

    printf("last warrior: ");
    printf("%d\n", getValue(head(list)));

    for (int i = 0; i < numberOfWarriors; i++)
        free(elements[i]);
    free(elements);

    deleteList(list);

    return 0;
}
