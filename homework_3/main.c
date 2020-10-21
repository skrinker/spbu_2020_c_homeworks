#include "../library/list/list.h"

int checkPosition(int position, List* list)
{
    while (position >= getSize(list) || position < 0) {
        printf("position less/more than necessary, try again \n");
        scanf("%d", &position);
    }
    return position;
}

int checkPositionToInsert(int position, List* list)
{
    while (position > getSize(list) || position < 0) {
        printf("position less/more than necessary, try again \n");
        scanf("%d", &position);
    }
    return position;
}

int main()
{
    int n = 0;
    printf("Input number of items: \n");
    scanf("%d", &n);
    ListElement** elements = (ListElement**)malloc(n * sizeof(ListElement*));
    List* list = createList();
    printf("Input value of items: \n");
    for (int i = 0; i < n; i++) {
        int number = 0;
        scanf("%d", &number);
        elements[i] = createListElement(number);
        insert(elements[i], i, list);
    }
    printList(list);
    printf("\n");

    printf("let's insert values \n");
    printf("choose position: \n");
    int position = 0;
    scanf("%d", &position);
    position = checkPositionToInsert(position, list);
    printf("input value: \n");
    int value = 0;
    scanf("%d", &value);
    ListElement* listElement1 = createListElement(value);
    insert(listElement1, position, list);
    printList(list);
    printf("\n");

    printf("let's get head value \n");
    printf("%d", getValue(head(list)));
    printf("\n");

    printf("let's get tail value \n");
    printf("%d", getValue(tail(list)));
    printf("\n");

    printf("let's retrieve list element value \n");
    printf("choose position: \n");
    scanf("%d", &position);
    position = checkPosition(position, list);

    printf("%d", getValue(retrieve(position, list)));
    printf("\n");

    printf("let's locate list element \n");
    scanf("%d", &value);
    ListElement* listElement2 = createListElement(value);
    printf("%d \n", locate(listElement2, list));
    ListElement* listElement3 = createListElementWithNext(value, retrieve(position + 1, list));
    printf("%d \n", locate(listElement3, list));

    printf("let's delete list element \n");
    printf("choose position: \n");
    scanf("%d", &position);
    position = checkPosition(position, list);

    deleteElement(position, list);
    printList(list);
    printf("\n");

    printf("are you sure you want to delete list [Y/n]?");
    char symbol = "";
    scanf("%s", &symbol);
    if (symbol == 'Y' || symbol == 'y') {
        deleteList(list);
    }

    free(listElement1);
    free(listElement2);
    free(listElement3);

    for (int i = 0; i < n; i++) {
        free(elements[i]);
    }
    free(elements);

    return 0;
}
