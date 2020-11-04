#include "avl.h"

typedef struct TreeNode {
    BinaryTreeNode* bst;
    int height;
} TreeNode;

TreeNode* createNodeAVL(BinaryTreeNode* bst)
{
    TreeNode* node = malloc(sizeof(TreeNode));
    node->bst = bst;
    node->height = 0;
    return node;
}
