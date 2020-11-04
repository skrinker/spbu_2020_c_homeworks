#include "avl.h"

struct AVLTree {
    BinarySearchTree* bst;
    TreeNode* root;
};

AVLTree* createAVLTree()
{
    BinarySearchTree* bstTree = createTree();
    AVLTree* tree = (AVLTree*)malloc(sizeof(AVLTree));
    tree->root = NULL;
    tree->bst = bstTree;

    return tree;
}
