#include "../avl/avlNode.h"

#ifndef __AVL_H__
#define __AVL_H__

typedef struct AVLTree AVLTree;

AVLTree* createAVLTree();
void deleteTree(AVLTree* tree);
bool exists(AVLTree* tree, int value);
TreeNode* addValue(AVLTree* tree, int value);
bool removeValue(AVLTree* tree, int value);
bool printTree(AVLTree* tree);
TreeNode* getRoot(AVLTree* tree);

#endif