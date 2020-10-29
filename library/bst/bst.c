#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode {
    int value;
    struct BinaryTreeNode* leftChild;
    struct BinaryTreeNode* rightChild;
};

struct BinarySearchTree {
    struct BinaryTreeNode* root;
};

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
    if (getValue(node) == value) {
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

bool changeParent(enum Direction d, BinaryTreeNode* parent, BinarySearchTree* tree, BinaryTreeNode* newNode)
{
    if (d == left) {
        parent->leftChild = newNode;
    }
    if (d == right) {
        parent->rightChild = newNode;
    }
    if (d == none) {
        tree->root = newNode;
    }
    return true;
}

bool removeRecursive(BinarySearchTree* tree, BinaryTreeNode* node, int value, BinaryTreeNode* parent, enum Direction d)
{
    if (getValue(node) == value) {
        if (isLeaf(node)) {
            free(node);
            changeParent(d, parent, tree, NULL);
        }
        if (getLeftChild(node) == NULL && getRightChild(node) != NULL) {
            changeParent(d, parent, tree, getRightChild(node));
            free(node);
            return true;
        }
    }
    if (getValue(node) > value && getLeftChild(node) != NULL) {
        return removeRecursive(tree, getLeftChild(node), value, node, left);
    }
    if (getValue(node) < value && getRightChild(node) != NULL) {
        return removeRecursive(tree, getRightChild(node), value, node, right);
    }
    return false;
}

bool removeValue(BinarySearchTree* tree, int value)
{
    if (isEmpty(tree)) {
        return false;
    }
    return removeRecursive(tree, tree->root, value, NULL, none);
}

void printSymmetricalRecursive(BinaryTreeNode* node)
{
    if (node == NULL)
        return;

    printSymmetricalRecursive(getLeftChild(node));
    printf("%d, ", getValue(node));
    printSymmetricalRecursive(getRightChild(node));
}

void printSymmetrical(BinarySearchTree* tree)
{
    printf("Here's your tree: ");
    if (tree != NULL)
        printSymmetricalRecursive(tree->root);
    printf("\n");
}

void printTree(BinaryTreeNode* node, bool isDecreasing)
{
    if (!node) {
        printf("\n");
        return;
    }
    isDecreasing ? printTree(getRightChild(node), isDecreasing) : printTree(getLeftChild(node), isDecreasing);
    printf("%d", getValue(node));
    isDecreasing ? printTree(getLeftChild(node), isDecreasing) : printTree(getRightChild(node), isDecreasing);
}

void printTreeByFormatRecursive(BinaryTreeNode* node)
{
    if (!node) {
        printf("null");
        return;
    }
    printf("(%d ", getValue(node));
    printTreeByFormatRecursive(getLeftChild(node));
    printf(" ");
    printTreeByFormatRecursive(getRightChild(node));
    printf(")");
}

bool printTreeByFormat(BinarySearchTree* tree)
{
    if (!tree)
        return false;
    printTreeByFormatRecursive(getRoot(tree));
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