#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Define the TreeNode structure
typedef struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function prototypes
TreeNode* createNode(int value);
TreeNode* insert(TreeNode *root, int value);
TreeNode* search(TreeNode *root, int value);
TreeNode* findMinimum(TreeNode *root);

int main() {
    // Basic setup
    TreeNode *root = NULL;

    // Example of insertion
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 18);

    // Test insertions
    assert(root != NULL);
    assert(root->value == 10);

    // Test searching
    TreeNode *searchResult = search(root, 7);
    printf("%d\n",searchResult->value);
    assert(searchResult != NULL && searchResult->value == 7);

    // Search for a non-existing value
    searchResult = search(root, 100);
    assert(searchResult == NULL);

    // Test finding minimum
    TreeNode *minNode = findMinimum(root);
    assert(minNode != NULL && minNode->value == 3);

    printf("All tests passed!\n");

    // Add more operations and tests as needed

    return 0;
}

l// Function to create a new TreeNode
TreeNode* createNode(int value) {
    // Allocate memory for new node and initialize it
    // Return the new node
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a value into the tree
TreeNode* insert(TreeNode *root, int value) {
    // Implement insertion logic
    // Return the updated root
    if (root == NULL) {
	root = createNode(value);
    } else if (value < root->value) {
	if (root->left == NULL) {
	    root->left = insert(root->left,value);
	} else {
	    insert(root->left,value);
	}
    } else if (value > root->value) {
	if (root->right == NULL) { root->right = insert(root->right,value); }
	else { insert(root->right,value); }
    }
    return root;
}

// Function to search for a value in the tree
TreeNode* search(TreeNode *root, int value) {
    // Implement search logic
    // Return the node if found, otherwise NULL
    if (root == NULL || root->value == value) {
	return root;
    }
    if (value < root->value) {
	return search(root->left,value);
    } else {
	return search(root->right,value);
    }
}

// Function to find the minimum value in the tree
TreeNode* findMinimum(TreeNode *root) {
    // Implement logic to find the minimum value
    // Return the node with minimum value
    if (root == NULL) {
	return root;
    }
    while (root->left != NULL) { root = root->left; }
    return root;
}
