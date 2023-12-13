#include <iostream>
#include <cassert>

// TreeNode structure definition
struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;

    // Constructor for convenience
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function prototypes
TreeNode* createNode(int value);
TreeNode* insert(TreeNode *root, int value);
int findMaximum(TreeNode *root);
int countNodes(TreeNode *root);
bool exists(TreeNode *root, int value);
int sumOfNodes(TreeNode *root);

int main() {
    // Create and insert values into your BST
    TreeNode *root = nullptr;
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
    assert(exists(root, 7) == true);  // Should exist
    assert(exists(root, 99) == false); // Should not exist

    // Test sumOfNodes
    assert(sumOfNodes(root) == 58); // Sum of 10 + 5 + 15 + 3 + 7 + 18

    std::cout << "All assertions passed!\n";

    // Free the allocated memory
    // Note: Implement a tree destructor if necessary to avoid memory leaks

    return 0;
}

// Placeholder function implementations
TreeNode* createNode(int value) {
    // TODO: Create a new TreeNode with the given value and return it
    return new TreeNode(value);
}

TreeNode* insert(TreeNode *root, int value) {
    // TODO: Insert the given value into the BST rooted at root
    if (root == nullptr) {
	root = createNode(value);
    } else if (value < root->value) {
	root->left = insert(root->left,value);
    } else if (value > root->value) {
	root->right = insert(root->right,value);
    }
    return root;
}

int findMaximum(TreeNode *root) {
    // TODO: Find and return the maximum value in the tree
    if (root == nullptr) {
	return -1;
    }
    while (root->right != nullptr) {
	root = root->right;
    }
    return root->value;
}

int countRecursive(TreeNode *root) {
    if (root == nullptr) {
	return 0;
    }

    return 1 + countRecursive(root->left) + countRecursive(root->right);
}

int countNodes(TreeNode *root) {
    // TODO: Count and return the number of nodes in the tree
    return countRecursive(root);
}

bool exists(TreeNode *root, int value) {
    // TODO: Check if the given value exists in the tree
    if (root == nullptr) {
	return false;
    } else if (root->value == value) {
	return true;
    }

    return exists(root->left,value) || exists(root->right,value);
}

int sumRecursive(TreeNode *root) {
    if (root == nullptr) {
	return 0;
    }

    return root->value + sumRecursive(root->left) + sumRecursive(root->right);
}

int sumOfNodes(TreeNode *root) {
    // TODO: Calculate and return the sum of all the nodes in the tree
    return sumRecursive(root);
}
