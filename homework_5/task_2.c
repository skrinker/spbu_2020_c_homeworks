#include "../library/avl/avl.h"
#include "stdio.h"
#include "stdlib.h"

int main()
{
    AVLTree* tree = createAVLTree();
    TreeNode* node = createNode(0);
    node = addValue(tree, 10);
    node = addValue(tree, 50);
    node = addValue(tree, 30);
    node = addValue(tree, 20);
    node = addValue(tree, 40);

    printTree(tree);

    return 0;
}
