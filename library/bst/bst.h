#ifndef __BST_H__
#define __BST_H__

#include <stdbool.h>

typedef struct BinarySearchTree BinarySearchTree;
typedef struct BinaryTreeNode BinaryTreeNode;

BinarySearchTree* createTree();
BinaryTreeNode* getLeftChild(BinaryTreeNode* node);
BinaryTreeNode* getRightChild(BinaryTreeNode* node);
int getValue(BinaryTreeNode* node);
void deleteTree(BinarySearchTree* tree);
bool exists(BinarySearchTree* tree, int value);
bool addValue(BinarySearchTree* tree, int value);
bool removeValue(BinarySearchTree* tree, int value);
void printTree(BinaryTreeNode* node, bool isDecreasing);
BinaryTreeNode* getRoot(BinarySearchTree* tree);
bool printTreeByFormat(BinarySearchTree* tree);

#endif
