#include "avlNode.h"

struct TreeNode {
    BinaryTreeNode* bst;
    int height;
    TreeNode* parent;
};

TreeNode* createNodeAVL(BinaryTreeNode* bst)
{
    TreeNode* node = malloc(sizeof(TreeNode));
    node->bst = bst;
    node->height = 0;
    node->parent = NULL;
    return node;
}