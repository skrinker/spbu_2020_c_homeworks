#include "../library/bst/bst.h"
#include <stdio.h>

int main()
{
    BinarySearchTree* tree = createTree();
    printf("%d", exists(tree, 4));
    addValue(tree, 4);
    printf("%d", exists(tree, 4));
    addValue(tree, 2);
    printf("%d", exists(tree, 2));
    addValue(tree, 1);
    printf("%d", exists(tree, 1));
    addValue(tree, 3);
    printf("%d", exists(tree, 3));
    addValue(tree, 5);
    printf("%d", exists(tree, 5));
    addValue(tree, 10);
    printf("%d", exists(tree, 10));
    printf("%d", exists(tree, 15));
    printf("%d", exists(tree, 7));

    printSymmetrical(tree);

    removeValue(tree, 10);
    printSymmetrical(tree);

    printf("All done!\n");
    return 0;
}