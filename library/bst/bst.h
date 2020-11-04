#include "bstNode.h"
#include <stdbool.h>

#ifndef __BST_H__
#define __BST_H__

typedef struct BinarySearchTree BinarySearchTree;

BinarySearchTree* createTree();

void deleteTree(BinarySearchTree* tree);
bool exists(BinarySearchTree* tree, int value);
bool addValue(BinarySearchTree* tree, int value);
bool removeValue(BinarySearchTree* tree, int value);
bool printTree(BinarySearchTree* tree);
BinaryTreeNode* getRoot(BinarySearchTree* tree);

#endif
