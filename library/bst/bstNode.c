#include "bstNode.h"

struct BinaryTreeNode {
    int value;
    struct BinaryTreeNode* leftChild;
    struct BinaryTreeNode* rightChild;
};

BinaryTreeNode* createNode(int value)
{
    BinaryTreeNode* node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    node->rightChild = NULL;
    node->leftChild = NULL;
    node->value = value;
    return node;
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

void updateRightChild(BinaryTreeNode* node, BinaryTreeNode* newNode)
{
    node->rightChild = newNode;
}

void updateLeftChild(BinaryTreeNode* node, BinaryTreeNode* newNode)
{
    node->leftChild = newNode;
}