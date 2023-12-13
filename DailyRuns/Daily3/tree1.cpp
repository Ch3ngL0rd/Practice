#include <iostream>
#include <cassert>

// Define the TreeNode structure
struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;

    // Constructor to initialize the node
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function prototypes
TreeNode* createNode(int value);
TreeNode* insert(TreeNode *root, int value);
TreeNode* search(TreeNode *root, int value);
TreeNode* findMinimum(TreeNode *root);

int main() {
    // Basic setup
    TreeNode *root = nullptr;

    // Example of insertion
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 18);

    // Test insertions
    assert(root != nullptr);
    assert(root->value == 10);

    // Test searching
    TreeNode *searchResult = search(root, 7);
    assert(searchResult != nullptr && searchResult->value == 7);

    // Search for a non-existing value
    searchResult = search(root, 100);
    assert(searchResult == nullptr);

    // Test finding minimum
    TreeNode *minNode = findMinimum(root);
    assert(minNode != nullptr && minNode->value == 3);

    std::cout << "All tests passed!\n";

    // Add more operations and tests as needed

    return 0;
}

// Function to create a new TreeNode
TreeNode* createNode(int value) {
    return new TreeNode(value);
}

// Function to insert a value into the tree
TreeNode* insert(TreeNode *root, int value) {
    if (root == nullptr) {
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
    if (root == nullptr || root->value == value) {
	return root;
    }
    if (value < root->value) {
	return search(root->left,value);
    } else if (value > root->value) {
	return search(root->right,value);
    }
    return nullptr;
}

// Function to find the minimum value in the tree
TreeNode* findMinimum(TreeNode *root) {
    if (root == nullptr) {
	return root;
    }
    while (root->left != nullptr) {
	root = root->left;
    }
    return root;
}
