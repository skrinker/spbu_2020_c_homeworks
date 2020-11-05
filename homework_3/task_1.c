#include "../library/list/list.h"

int main()
{
    int n = 0;
    printf("Input number of items: \n");
    scanf("%d", &n);
    List* list = createList();
    printf("Input value of items: \n");
    for (int i = 0; i < n; i++) {
        int number = 0;
        scanf("%d", &number);
        insert(createListElement(number), i, list);
    }
    printList(list);
    printf("\n");

    printf("let's insert values \n");
    printf("choose position: \n");
    int position = 0;
    scanf("%d", &position);
    printf("input value: \n");
    int value = 0;
    scanf("%d", &value);
    while (!insert(createListElement(value), position, list)) {
        printf("error, try again \n");
        printf("choose position: \n");
        scanf("%d", &position);
        printf("input value: \n");
        scanf("%d", &value);
    }
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
    while (retrieve(position, list) == NULL) {
        printf("error, try again \n");
        printf("choose position: \n");
        scanf("%d", &position);
    }

    printf("%d", getValue(retrieve(position, list)));
    printf("\n");

    printf("let's locate list element \n");
    position = 0;
    printf("head: \t");
    printf("%d \n", locate(retrieve(position, list), list));
    position = getSize(list) - 1;
    printf("tail: \t");
    printf("%d \n", locate(retrieve(position, list), list));
    --position;
    ListElement* number3 = createListElement(getValue(head(list)));
    printf("head value without next: \t");
    printf("%d \n", locate(number3, list));

    printf("let's delete list element \n");
    printf("choose position: \n");
    scanf("%d", &position);

    while (!deleteElement(position, list)) {
        printf("error, try again \n");
        printf("choose position: \n");
        scanf("%d", &position);
    }
    printList(list);

    printf("let's delete list \n");
    printList(list);
    deleteList(list);

    free(number3);

    return 0;
}
