#include "../library/avl/avl.h"
#include <stdio.h>

void printMenu()
{
    printf("0 - выйти \n");
    printf("1 - добавить элемент в множество \n");
    printf("2 - удалить элемент из множества \n");
    printf("3 - проверить, содержится ли элемент в множестве \n");
    printf("4 - напечатать элементы множества в порядке возрастания \n");
    printf("5 - напечатать элементы множества в порядке убывания \n");
    printf("6 - напечатать элементы множества в формате (a b c), где a — значениев узле, а b и c — аналогичные представления поддеревьев правого и левого потомка \n");
}

void addSetValue(AVLTree* set)
{
    int value = 0;
    printf("введите значение элемента, которое вы хотите вставить \n");
    scanf("%d", &value);
    addValue(set, value);
}

bool isSetValueContains(AVLTree* set)
{
    int value = 0;
    printf("введите значение, которое вы хотите проверить на принадлежность множеству: \n");
    scanf("%d", &value);
    printf("данное значение: %s", (exists(set, value) ? "содержится \n" : "не содержится \n"));
}

void deleteSetValue(AVLTree* set)
{
    int value = 0;
    printf("введите значение, которое вы хотите удалить из множества: \n");
    scanf("%d", &value);
    if (!exists(set, value)) {
        printf("такого элемента нет в множестве \n");
        return;
    }
    removeValue(set, value);
}

void printSetByDecrease(AVLTree* set)
{
    printSubTree(getRoot(set), true);
    printf("\n");
}

void printSetByIncrease(AVLTree* set)
{
    printSubTree(getRoot(set), false);
    printf("\n");
}

bool printSet(AVLTree* set)
{
    return printTree(set);
}

bool handleRequest(AVLTree* set)
{
    int command = -1;
    scanf("%d", &command);
    switch (command) {
    case 0:
        deleteTree(set);
        return false;
    case 1:
        addSetValue(set);
        break;
    case 2:
        deleteSetValue(set);
        break;
    case 3:
        isSetValueContains(set);
        break;
    case 4:
        printSetByIncrease(set);
        break;
    case 5:
        printSetByDecrease(set);
        break;
    case 6: {
        if (!printSet(set))
            printf("множество пустое, сначала добавьте элементы \n");
        break;
    }
    default:
        printf("нет такой команды! \n");
        break;
    }
    return true;
}

int main()
{
    AVLTree* set = createAVLTree();
    while (true) {
        printMenu();
        if (!handleRequest(set))
            break;
    }
    return 0;
}
