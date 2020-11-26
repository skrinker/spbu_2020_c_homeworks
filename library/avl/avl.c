#include "avl.h"

struct AVLTree {
    TreeNode* root;
};

enum Direction {
    left,
    right,
    none
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
    if (node == NULL) {
        return createNode(value);
    }
    if (value < getValue(node)) {
        updateLeftChild(node, addValueRecursive(getLeftChild(node), value));
    } else if (value > getValue(node)) {
        updateRightChild(node, addValueRecursive(getRightChild(node), value));
    } else
        return node;

    fixHeight(node);
    return balanceNode(node);
}

void addValue(AVLTree* tree, int value)
{
    tree->root = addValueRecursive(tree->root, value);
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

bool changeParent(AVLTree* tree, TreeNode* parent, TreeNode* newNode, enum Direction direction)
{
    if (direction == left) {
        updateLeftChild(parent, newNode);
    }
    if (direction == right) {
        updateRightChild(parent, newNode);
    }
    if (direction == none) {
        tree->root = newNode;
    }
    return true;
}

bool printTree(AVLTree* tree)
{
    if (!getRoot(tree))
        return false;
    printTreeRecursive(getRoot(tree));
    printf("\n");
    return true;
}

void deleteTreeRecursive(TreeNode* node)
{
    if (node == NULL)
        return;
    deleteTreeRecursive(getLeftChild(node));
    deleteTreeRecursive(getRightChild(node));
    free(node);
}

void deleteTree(AVLTree* tree)
{
    deleteTreeRecursive(tree->root);
    free(tree);
}

bool isLeaf(TreeNode* node)
{
    return getLeftChild(node) == NULL && getRightChild(node) == NULL;
}

bool existsRecursive(TreeNode* node, int value)
{
    if (value == getValue(node)) {
        return true;
    }
    if (value < getValue(node) && getLeftChild(node) != NULL) {
        return existsRecursive(getLeftChild(node), value);
    }
    if (value > getValue(node) && getRightChild(node) != NULL) {
        return existsRecursive(getRightChild(node), value);
    }
    return false;
}

bool exists(AVLTree* tree, int value)
{
    if (isEmpty(tree)) {
        return false;
    }
    return existsRecursive(tree->root, value);
}

bool removeRecursive(AVLTree* tree, TreeNode* node, TreeNode* parent, int value, enum Direction direction)
{
    if (getValue(node) == value) {
        if (isLeaf(node))
            changeParent(tree, parent, NULL, direction);
        if (getLeftChild(node) == NULL && getRightChild(node) != NULL) {
            changeParent(tree, parent, getRightChild(node), direction);
            fixHeight(getRightChild(node));
        }
        if (getLeftChild(node) != NULL && getRightChild(node) == NULL) {
            changeParent(tree, parent, getLeftChild(node), direction);
            fixHeight(getLeftChild(node));
        }
        if (getLeftChild(node) != NULL && getRightChild(node) != NULL) {
            TreeNode* minimumRightParent = findMinimumParent(getRightChild(node));
            if (parent == NULL) {
                if (getLeftChild(minimumRightParent) == NULL) {
                    updateLeftChild(minimumRightParent, getLeftChild(node));
                    fixHeight(minimumRightParent);
                    tree->root = minimumRightParent;
                } else {
                    updateLeftChild(getLeftChild(minimumRightParent), getLeftChild(node));
                    updateRightChild(getLeftChild(minimumRightParent), minimumRightParent);
                    tree->root = getLeftChild(minimumRightParent);
                    fixHeight(getLeftChild(minimumRightParent));
                    updateLeftChild(minimumRightParent, NULL);
                }
            } else {
                if (getLeftChild(minimumRightParent) == NULL) {
                    changeParent(tree, parent, minimumRightParent, direction);
                    updateLeftChild(minimumRightParent, getLeftChild(node));
                    fixHeight(minimumRightParent);
                } else {
                    changeParent(tree, parent, getLeftChild(minimumRightParent), direction);
                    updateLeftChild(getLeftChild(minimumRightParent), getLeftChild(node));
                    fixHeight(getLeftChild(minimumRightParent));
                }
            }
        }
        fixHeight(parent);
        tree->root = balanceNode(parent);
        free(node);
        return true;
    }
    if (getValue(node) > value && getLeftChild(node) != NULL) {
        return removeRecursive(tree, getLeftChild(node), node, value, left);
    }
    if (getValue(node) < value && getRightChild(node) != NULL) {
        return removeRecursive(tree, getRightChild(node), node, value, right);
    }
    return false;
}

bool removeValue(AVLTree* tree, int value)
{
    if (isEmpty(tree) || !exists(tree, value))
        return false;
    return removeRecursive(tree, tree->root, NULL, value, none);
}
