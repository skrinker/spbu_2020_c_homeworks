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
    node->height = 0;
    node->right = NULL;
    node->left = NULL;
    node->value = value;
    return node;
}

TreeNode* getLeftChild(TreeNode* node)
{
    return node->left;
}

TreeNode* getRightChild(TreeNode* node)
{
    return node->right;
};

TreeNode* findMinimumParent(TreeNode* node);

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
    TreeNode* rotateChild = getLeftChild(node);
    TreeNode* rightRotateChild = getRightChild(rotateChild);

    updateRightChild(rotateChild, node);
    updateLeftChild(node, rightRotateChild);

    updateHeight(node, max(getHeight(getLeftChild(node)), getHeight(getRightChild(node))) + 1);
    updateHeight(rotateChild, max(getHeight(getLeftChild(rotateChild)), getHeight(getRightChild(rotateChild))) + 1);

    return node;
}

TreeNode* leftRotate(TreeNode* node)
{
    TreeNode* rotateChild = getRightChild(node);
    TreeNode* leftRotateChild = getLeftChild(rotateChild);

    updateLeftChild(rotateChild, node);
    updateRightChild(node, leftRotateChild);

    updateHeight(node, max(getHeight(getLeftChild(node)), getHeight(getRightChild(node))) + 1);
    updateHeight(rotateChild, max(getHeight(getLeftChild(rotateChild)), getHeight(getRightChild(rotateChild))) + 1);

    return node;
}

int getBalance(TreeNode* node)
{
    return (node == NULL) ? 0 : getHeight(getLeftChild(node)) - getHeight(getRightChild(node));
}

TreeNode* balance(TreeNode* node, int balance)
{
    //left left
    if (balance > 1 && getValue(node) < getValue(getLeftChild(node))) {
        return rightRotate(node);
    }
    // left right
    if (balance > 1 && getValue(node) > getValue(getLeftChild(node))) {
        updateLeftChild(getLeftChild(node), leftRotate(getLeftChild(node)));
        return rightRotate(node);
    }
    // right right
    if (balance < -1 && getValue(node) > getValue(getRightChild(node))) {
        return leftRotate(node);
    }
    // right left
    if (balance < -1 && getValue(node) < getValue(getRightChild(node))) {
        updateRightChild(getRightChild(node), rightRotate(getRightChild(node)));
        return leftRotate(node);
    }
}