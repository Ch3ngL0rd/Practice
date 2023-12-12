#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct TreeNode
{
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function prototypes
TreeNode *createNode(int value);
TreeNode *insert(TreeNode *root, int value);
int findMaximum(TreeNode *root);
int countNodes(TreeNode *root);
int exists(TreeNode *root, int value);
int sumOfNodes(TreeNode *root);

int main()
{
    // Create and insert values into your BST
    TreeNode *root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 18);

    // Test findMaximum
    assert(findMaximum(root) == 18);

    // Test countNodes
    assert(countNodes(root) == 6);

    // Test exists
    assert(exists(root, 7) == 1);  // Should exist
    assert(exists(root, 99) == 0); // Should not exist

    // Test sumOfNodes
    assert(sumOfNodes(root) == 58); // Sum of 10 + 5 + 15 + 3 + 7 + 18

    printf("All assertions passed!\n");

    // Free the allocated memory
    // Note: Implement a tree destructor if necessary to avoid memory leaks

    return 0;
}

// Implement the other functions as previously described
TreeNode* createNode(int value) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* insert(TreeNode *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

int findMaximum(TreeNode *root) {
    // Implement the logic to find the maximum value in the BST
    if (root == NULL || root->right == NULL) {
	return root->value;
    }
    return findMaximum(root->right);
}

// Returns how many nodes are below it
int countNodesRecursive(TreeNode *root) {
    if (root == NULL) return 0;
    return (1 + countNodesRecursive(root->left) + countNodesRecursive(root->right));
}

int countNodes(TreeNode *root) {
    // Implement the logic to count the nodes in the BST
    return countNodesRecursive(root);
}

int exists(TreeNode *root, int value) {
    // Implement the logic to check if a value exists in the BST
    if (root == NULL) {
	return 0;
    } else if (root->value == value) {
	return 1;
    } else if (value < root->value) {
	return exists(root->left,value);
    } else if (value > root->value) {
	return exists(root->right,value);
    }
}

int sumOfNodesRecursive(TreeNode *root, int value) {
    if (root == NULL) return 0;
    return (root->value + sumOfNodesRecursive(root->left,0) + sumOfNodesRecursive(root->right,0));
}	

int sumOfNodes(TreeNode *root) {
    // Implement the logic to calculate the sum of all values in the BST
    return sumOfNodesRecursive(root,0);
}
