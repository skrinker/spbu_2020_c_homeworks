#include "avl.h"

struct AVLTree {
    TreeNode* root;
};

AVLTree* createAVLTree()
{
    AVLTree* tree = (AVLTree*)malloc(sizeof(AVLTree));
    tree->root = NULL;
    return tree;
}

bool isEmpty(AVLTree* tree)
{
    return (tree->root == NULL);
}

TreeNode* getRoot(AVLTree* tree)
{
    return (tree == NULL) ? NULL : tree->root;
}
TreeNode* addValueRecursive(TreeNode* node, int value)
{
    if (node == NULL)
        return createNode(value);
    if (value < getValue(node)) {
        updateLeftChild(node, addValueRecursive(getLeftChild(node), value));
        updateHeight(node, 1 + max(getHeight(getLeftChild(node)), getHeight(getRightChild(node))));
    } else if (value > getValue(node)) {
        updateRightChild(node, addValueRecursive(getRightChild(node), value));
        updateHeight(node, 1 + max(getHeight(getLeftChild(node)), getHeight(getRightChild(node))));
    } else
        return node;
}

TreeNode* addValue(AVLTree* tree, int value)
{
    if (isEmpty(tree)) {
        tree->root = createNode(value);
        return getRoot(tree);
    }
    TreeNode* addedNode = addValueRecursive(tree->root, value);
    return balance(addedNode, getBalance(addedNode));
}

void printTreeRecursive(TreeNode* node)
{
    if (!node) {
        printf("null");
        return;
    }
    printf("(%d ", getValue(node));
    printTreeRecursive(getLeftChild(node));
    printf(" ");
    printTreeRecursive(getRightChild(node));
    printf(")");
}

bool printTree(AVLTree* tree)
{
    if (!getRoot(tree))
        return false;
    printTreeRecursive(getRoot(tree));
    printf("\n");
    return true;
}