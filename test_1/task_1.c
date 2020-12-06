#include "../library/doubleLinkedList/list.h"

int main()
{
    List* list = createList();
    insert(1, 0, list);
    insert(2, 1, list);
    insert(2, 2, list);
    insert(4, 3, list);
    printList(list);
    printf("%s", isSymmetric(list) ? "симметричен" : "не симметричен");
}