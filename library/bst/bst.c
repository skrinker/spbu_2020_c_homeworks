#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTreeNode {
    int value;
    struct BinaryTreeNode* leftChild;
    struct BinaryTreeNode* rightChild;
} BinaryTreeNode;

struct BinarySearchTree {
    struct BinaryTreeNode* root;
};

BinaryTreeNode* getLeftChild(BinaryTreeNode* node);
BinaryTreeNode* getRightChild(BinaryTreeNode* node);
BinaryTreeNode* findMinimum(BinaryTreeNode* node);
BinaryTreeNode* getRoot(BinarySearchTree* tree);
void printSubTree(BinaryTreeNode* node, bool isDecreasing);
int getValue(BinaryTreeNode* node);

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

BinaryTreeNode* createNode(int value)
{
    BinaryTreeNode* node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    node->rightChild = NULL;
    node->leftChild = NULL;
    node->value = value;
    return node;
}

bool addValueRecursive(BinaryTreeNode* node, int value)
{
    if (getValue(node) == value) {
        return false;
    }
    if (value < getValue(node)) {
        if (getLeftChild(node) == NULL) {
            node->leftChild = createNode(value);
            return true;
        } else
            return addValueRecursive(getLeftChild(node), value);
    }
    if (value > getValue(node)) {
        if (getRightChild(node) == NULL) {
            node->rightChild = createNode(value);
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

BinaryTreeNode* removeRecursive(BinarySearchTree* tree, BinaryTreeNode* node, int value)
{
    if (node == NULL)
        return node;
    if (value < getValue(node)) {
        node->leftChild = removeRecursive(tree, getLeftChild(node), value);
    } else if (value > getValue(node)) {
        node->rightChild = removeRecursive(tree, getRightChild(node), value);
    } else {
        if (getLeftChild(node) == NULL) {
            if (getValue(getRoot(tree)) == value)
                tree->root = getRightChild(node);
            BinaryTreeNode* temp = getRightChild(node);
            free(node);
            return temp;
        } else if (getRightChild(node) == NULL) {
            if (getValue(getRoot(tree)) == value)
                tree->root = getLeftChild(node);
            BinaryTreeNode* temp = getLeftChild(node);
            free(node);
            return temp;
        }
        BinaryTreeNode* temp = findMinimum(getRightChild(node));
        node->value = getValue(temp);
        free(temp);
        node->rightChild = removeRecursive(tree, getRightChild(node), getValue(node));
    }
    return node;
}

bool removeValue(BinarySearchTree* tree, int value)
{
    if (isEmpty(tree)) {
        return false;
    }
    removeRecursive(tree, tree->root, value);
    return true;
}

void printSymmetricalRecursive(BinaryTreeNode* node)
{
    if (node == NULL)
        return;

    printSymmetricalRecursive(getLeftChild(node));
    printf("%d, ", getValue(node));
    printSymmetricalRecursive(getRightChild(node));
}

BinaryTreeNode* findMinimum(BinaryTreeNode* node)
{
    BinaryTreeNode* current = node;
    while (getLeftChild(current) != NULL) {
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

BinaryTreeNode* getRoot(BinarySearchTree* tree)
{
    return tree ? tree->root : NULL;
}

BinaryTreeNode* getLeftChild(BinaryTreeNode* node)
{
    return node ? node->leftChild : NULL;
}

BinaryTreeNode* getRightChild(BinaryTreeNode* node)
{
    return node ? node->rightChild : NULL;
}

int getValue(BinaryTreeNode* node)
{
    return node->value;
}
