#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

struct BinarySearchTree {
    struct BinaryTreeNode* root;
};

BinaryTreeNode* getRoot(BinarySearchTree* tree)
{
    return tree ? tree->root : NULL;
}

enum Direction {
    left,
    right,
    none
};

BinarySearchTree* createTree()
{
    BinarySearchTree* newTree = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    newTree->root = NULL;
    return newTree;
}

void deleteTreeRecursive(BinaryTreeNode* node)
{
    if (node == NULL)
        return;
    deleteTreeRecursive(getLeftChild(node));
    deleteTreeRecursive(getRightChild(node));
    free(node);
}

void deleteTree(BinarySearchTree* tree)
{
    deleteTreeRecursive(tree->root);
    free(tree);
}

bool existsRecursive(BinaryTreeNode* node, int value)
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

bool isEmpty(BinarySearchTree* tree)
{
    return (tree->root == NULL);
}

bool exists(BinarySearchTree* tree, int value)
{
    if (isEmpty(tree)) {
        return false;
    }
    return existsRecursive(tree->root, value);
}

bool changeParent(BinarySearchTree* tree, BinaryTreeNode* parent, BinaryTreeNode* newNode, enum Direction direction)
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

bool addValueRecursive(BinaryTreeNode* node, int value)
{
    if (getValue(node) == value) {
        return false;
    }
    if (value < getValue(node)) {
        if (getLeftChild(node) == NULL) {
            updateLeftChild(node, createNode(value));
            return true;
        } else
            return addValueRecursive(getLeftChild(node), value);
    }
    if (value > getValue(node)) {
        if (getRightChild(node) == NULL) {
            updateRightChild(node, createNode(value));
            return true;
        } else
            return addValueRecursive(getRightChild(node), value);
    }
}

bool addValue(BinarySearchTree* tree, int value)
{
    if (isEmpty(tree)) {
        tree->root = createNode(value);
    }
    return addValueRecursive(tree->root, value);
}

bool isLeaf(BinaryTreeNode* node)
{
    return getLeftChild(node) == NULL && getRightChild(node) == NULL;
}

bool removeRecursive(BinarySearchTree* tree, BinaryTreeNode* node, BinaryTreeNode* parent, int value, enum Direction direction)
{
    if (isEmpty(tree) || !exists(tree, value))
        return false;
    if (getValue(node) == value) {
        if (isLeaf(node))
            changeParent(tree, parent, NULL, direction);
        if (getLeftChild(node) == NULL && getRightChild(node) != NULL)
            changeParent(tree, parent, getRightChild(node), direction);
        if (getLeftChild(node) != NULL && getRightChild(node) == NULL)
            changeParent(tree, parent, getLeftChild(node), direction);
        if (getLeftChild(node) != NULL && getRightChild(node) != NULL) {
            BinaryTreeNode* minimumRightParent = findMinimumParent(getRightChild(node));
            if (parent == NULL) {
                if (getLeftChild(minimumRightParent) == NULL) {
                    updateLeftChild(minimumRightParent, getLeftChild(node));
                    tree->root = minimumRightParent;
                } else {
                    updateLeftChild(getLeftChild(minimumRightParent), getLeftChild(node));
                    updateRightChild(getLeftChild(minimumRightParent), minimumRightParent);
                    tree->root = getLeftChild(minimumRightParent);
                    updateLeftChild(minimumRightParent, NULL);
                }
            } else {
                changeParent(tree, parent, getLeftChild(minimumRightParent), direction);
            }
        }
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

bool removeValue(BinarySearchTree* tree, int value)
{
    return removeRecursive(tree, tree->root, NULL, value, none);
}

void printSymmetricalRecursive(BinaryTreeNode* node)
{
    if (node == NULL)
        return;

    printSymmetricalRecursive(getLeftChild(node));
    printf("%d, ", getValue(node));
    printSymmetricalRecursive(getRightChild(node));
}

BinaryTreeNode* findMinimumParent(BinaryTreeNode* node)
{
    BinaryTreeNode* current = node;
    while (getLeftChild(getLeftChild(current)) != NULL) {
        current = getLeftChild(current);
    }
    return current;
}

void printSymmetrical(BinarySearchTree* tree)
{
    printf("Here's your tree: ");
    if (tree != NULL)
        printSymmetricalRecursive(tree->root);
    printf("\n");
}

void printSubTree(BinaryTreeNode* node, bool isDecreasing)
{
    if (!node) {
        return;
    }
    isDecreasing ? printSubTree(getRightChild(node), isDecreasing) : printSubTree(getLeftChild(node), isDecreasing);
    printf("%d ", getValue(node));
    isDecreasing ? printSubTree(getLeftChild(node), isDecreasing) : printSubTree(getRightChild(node), isDecreasing);
}

void printTreeRecursive(BinaryTreeNode* node)
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

bool printTree(BinarySearchTree* tree)
{
    if (!getRoot(tree))
        return false;
    printTreeRecursive(getRoot(tree));
    printf("\n");
    return true;
}
