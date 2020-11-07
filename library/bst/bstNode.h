#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTreeNode BinaryTreeNode;

BinaryTreeNode* createNode(int value);
BinaryTreeNode* getLeftChild(BinaryTreeNode* node);
BinaryTreeNode* getRightChild(BinaryTreeNode* node);
BinaryTreeNode* findMinimumParent(BinaryTreeNode* node);
int getValue(BinaryTreeNode* node);
void printSubTree(BinaryTreeNode* node, bool isDecreasing);
void updateRightChild(BinaryTreeNode* node, BinaryTreeNode* newNode);
void updateLeftChild(BinaryTreeNode* node, BinaryTreeNode* newNode);
