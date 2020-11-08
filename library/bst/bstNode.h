#include <stdbool.h>
#include <stdlib.h>

typedef struct BinaryTreeNode BinaryTreeNode;

BinaryTreeNode* createNode(int value);
BinaryTreeNode* getLeftChild(BinaryTreeNode* node);
BinaryTreeNode* getRightChild(BinaryTreeNode* node);
BinaryTreeNode* findMinimumParent(BinaryTreeNode* node);
void printSubTree(BinaryTreeNode* node, bool isDecreasing);
int getValue(BinaryTreeNode* node);
void updateRightChild(BinaryTreeNode* node, BinaryTreeNode* newNode);
void updateLeftChild(BinaryTreeNode* node, BinaryTreeNode* newNode);
