#include <stdio.h>
#include <stdlib.h>

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
    root = insert(root,5);
    root = insert(root,11);
    root = insert(root,4);
    root = insert(root,3);
    printf("Root value is %d\n",root->value);
    printf("Right value is %d\n",root->right->value);
    printf("Left value is %d\n",root->left->value);
    // Continue with more insertions

    // Example of searching
    // Call search function and handle the result
    int value = 3;
    TreeNode *node = search(root,value);
    if (node == NULL) printf("Node with value %d not found\n",value);
    else { printf("Found node!\n"); }

    // Example of finding minimum
    // Call findMinimum function and handle the result
    TreeNode* minimum = findMinimum(root);
    if (minimum == NULL) { exit(1); }
    printf("The minimum value is %d.\n",minimum->value);
    // Add more operations and tests as needed

    return 0;
}

// Function to create a new TreeNode
TreeNode* createNode(int value) {
    // Allocate memory for new node and initialize it
    // Return the new node
	TreeNode *node = (TreeNode*) malloc(sizeof(TreeNode));
	if (node == NULL) {
		printf("Out of memory!\n");
		exit(1);
	}
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
	root->left = insert(root->left,value);
    } else if (value > root->value) {
	root->right = insert(root->right,value);
    }
    return root;
}

// Function to search for a value in the tree
TreeNode* search(TreeNode *root, int value) {
    // Implement search logic
    // Return the node if found, otherwise NULL
    if (root == NULL) {
	return NULL;
    } else if (root->value == value) {
	return root;
    } else if (value < root->value) {
	return search(root->left,value);
    } else if (value > root->value) {
	return search(root->right,value);
    } else {
	printf("Duplicate value found %d\n",value);
	exit(1);
    }
}

// Function to find the minimum value in the tree
TreeNode* findMinimum(TreeNode *root) {
    // Implement logic to find the minimum value
    // Return the node with minimum value
    if (root == NULL) {
	return NULL;
    } else if (root->left == NULL) {
	return root;
    } else {
	return findMinimum(root->left);
    }
}

TreeNode* findMinimumIterative(TreeNode *root) {
    if (root == NULL) {
	return NULL;
    }

    while (root->left != NULL) {
	root = root->left;
    }
    return root;
}
