#include "avlNode.h"

struct TreeNode {
    int height;
    int value;
    TreeNode* right;
    TreeNode* left;
};

TreeNode* createNode(int value)
{
    TreeNode* node = malloc(sizeof(TreeNode));
    node->height = 1;
    node->right = NULL;
    node->left = NULL;
    node->value = value;
    return node;
}

TreeNode* getLeftChild(TreeNode* node)
{
    return node ? node->left : NULL;
}

TreeNode* getRightChild(TreeNode* node)
{
    return node ? node->right : NULL;
};

int getValue(TreeNode* node)
{
    return node->value;
};

void printSubTree(TreeNode* node, bool isDecreasing)
{
    if (!node)
        return;
    isDecreasing ? printSubTree(getRightChild(node), isDecreasing) : printSubTree(getLeftChild(node), isDecreasing);
    printf("%d ", getValue(node));
    isDecreasing ? printSubTree(getLeftChild(node), isDecreasing) : printSubTree(getRightChild(node), isDecreasing);
}

TreeNode* findMinimumParent(TreeNode* node)
{
    TreeNode* current = node;
    while (getLeftChild(getLeftChild(current)) != NULL) {
        current = getLeftChild(current);
    }
    return current;
}

void updateRightChild(TreeNode* node, TreeNode* newNode)
{
    node->right = newNode;
}

void updateLeftChild(TreeNode* node, TreeNode* newNode)
{
    node->left = newNode;
}

int getHeight(TreeNode* node)
{
    return (node == NULL) ? 0 : node->height;
}

void updateHeight(TreeNode* node, int newHeight)
{
    node->height = newHeight;
}

TreeNode* rightRotate(TreeNode* node)
{
    TreeNode* pivot = getLeftChild(node);

    updateLeftChild(node, getRightChild(pivot));
    updateRightChild(pivot, node);

    fixHeight(node);
    fixHeight(pivot);

    return pivot;
}

TreeNode* leftRotate(TreeNode* node)
{
    TreeNode* pivot = getRightChild(node);

    updateRightChild(node, getLeftChild(pivot));
    updateLeftChild(pivot, node);

    fixHeight(node);
    fixHeight(pivot);

    return pivot;
}

int getBalance(TreeNode* node)
{
    return (node == NULL) ? 0 : getHeight(getRightChild(node)) - getHeight(getLeftChild(node));
}

void fixHeight(TreeNode* node)
{
    updateHeight(node, 1 + max(getHeight(getLeftChild(node)), getHeight(getRightChild(node))));
}

TreeNode* balanceNode(TreeNode* node)
{
    if (getBalance(node) == 2) {
        if (getBalance(getRightChild(node)) < 0) {
            updateRightChild(node, rightRotate(getRightChild(node)));
        }
        node = leftRotate(node);
    }
    if (getBalance(node) == -2) {
        if (getBalance(getLeftChild(node)) > 0) {
            updateLeftChild(node, rightRotate(getLeftChild(node)));
        }
        node = rightRotate(node);
    }
    return node;
}
