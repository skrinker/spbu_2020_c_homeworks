#include "list.c"

int main()
{
    int n = 0;
    printf("Input number of items: \n");
    scanf("%d", &n);
    ListElement** elements = (ListElement**)malloc(n * sizeof(ListElement));
    List* list = createList();
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
    while (position > list->size) {
        printf("position more than list length, try again \n");
        scanf("%d", &position);
    }
    printf("input value: \n");
    int value = 0;
    scanf("%d", &value);
    ListElement* listElement1 = createListElement(value);
    insert(listElement1, position, list);
    printList(list);
    printf("\n");

    printf("let's get head value \n");
    printf("%d", head(list)->value);
    printf("\n");

    printf("let's get tail value \n");
    printf("%d", tail(list)->value);
    printf("\n");

    printf("let's retrieve list element value \n");
    printf("choose position: \n");
    scanf("%d", &position);
    while (position >= list->size) {
        printf("position more than list length, try again \n");
        scanf("%d", &position);
    }
    printf("%d", retrieve(position, list)->value);
    printf("\n");

    printf("let's locate list element \n");
    scanf("%d", &value);
    ListElement* listElement2 = createListElement(value);
    printf("%d", locate(listElement2, list));
    printf("\n");

    printf("let's delete list element \n");
    printf("choose position: \n");
    scanf("%d", &position);
    while (position >= list->size) {
        printf("position more than list length, try again \n");
        scanf("%d", &position);
    }
    deleteElement(position, list);
    printList(list);
    printf("\n");

    free(listElement1);
    free(listElement2);
    for (int i = 0; i < n; i++) {
        free(elements[i]);
    }
    free(elements);
    free(list);
    return 0;
}