#ifndef __BST_H__
#define __BST_H__

#include <stdbool.h>

typedef struct BinarySearchTree BinarySearchTree;

BinarySearchTree* createTree();
void removeTree(BinarySearchTree* tree);
bool exists(BinarySearchTree* tree, int value);
bool addValue(BinarySearchTree* tree, int value);
bool removeValue(BinarySearchTree* tree, int value);
void printSymmetrical(BinarySearchTree* tree);

#endif
