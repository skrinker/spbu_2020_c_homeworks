#include "../commonUtils/numericOperations.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode TreeNode;

TreeNode* createNode(int value);

TreeNode* getLeftChild(TreeNode* node);
TreeNode* getRightChild(TreeNode* node);
int getValue(TreeNode* node);
int getHeight(TreeNode* node);

TreeNode* findMinimumParent(TreeNode* node);
void printSubTree(TreeNode* node, bool isDecreasing);

void updateRightChild(TreeNode* node, TreeNode* newNode);
void updateLeftChild(TreeNode* node, TreeNode* newNode);
void updateHeight(TreeNode* node, int newHeight);

TreeNode* leftRotate(TreeNode* node);
TreeNode* rightRotate(TreeNode* node);

TreeNode* balanceNode(TreeNode* node);
int getBalance(TreeNode* node);

void fixHeight(TreeNode* node);
