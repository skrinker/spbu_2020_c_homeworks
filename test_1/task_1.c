#include "list.c"

int main()
{
    // printf("Введите стопку")

    int size1 = 0;
    int size2 = 0;

    List* a = createList();
    int difficult = 0;
    printf("введите количество конспектов");
    scanf("%d", &size1);
    printf("введите сложность конспектов");
    for (int i = 0; i < size1; i++) {
        scanf("%d", difficult);
        push(a, difficult);
    }

    List* b = createList();
    printf("введите количество конспектов");
    scanf("%d", &size2);
    printf("введите сложность конспектов");
    for (int i = 0; i < size1; i++) {
        scanf("%d", difficult);
        push(b, difficult);
    }

    push(2, b);
    push(4, b);

    List* c = createList();
    sortedMerge(a, b, c);
    printList(c);

    free(a);
    free(b);
    free(c);
    return 0;
}