#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function prototypes
TreeNode* createNode(int value);
TreeNode* insert(TreeNode *root, int value);
TreeNode* deleteNode(TreeNode *root, int value);
TreeNode* findInOrderSuccessor(TreeNode *root, TreeNode *node);
int findHeight(TreeNode *root);
int isBalanced(TreeNode *root);
TreeNode* convertToDoublyLinkedList(TreeNode *root);
TreeNode* findLowestCommonAncestor(TreeNode *root, int value1, int value2);

int main() {
    // Create and insert values into your BST
    TreeNode *root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 12);
    root = insert(root, 18);

    // Test deleteNode
    root = deleteNode(root, 3); // Assuming 3 is a leaf node
    // Add more assertions based on the structure of your tree after deletion

    // Test findInOrderSuccessor
    TreeNode *node = search(root, 10); // Assuming this function exists
    TreeNode *successor = findInOrderSuccessor(root, node);
    assert(successor->value == 12); // Change as per your tree structure

    // Test findHeight
    int height = findHeight(root);
    assert(height > 0); // Modify as needed based on your tree's height

    // Test isBalanced
    int balanced = isBalanced(root);
    assert(balanced == 1 || balanced == 0); // 1 for true, 0 for false

    // Test convertToDoublyLinkedList
    TreeNode *head = convertToDoublyLinkedList(root);
    // Add specific checks for your linked list here

    // Test findLowestCommonAncestor
    TreeNode *lca = findLowestCommonAncestor(root, 5, 15);
    assert(lca->value == 10); // Modify as per your tree

    printf("All tests executed!\n");

    // Remember to free the allocated memory
    // Implement a tree destructor if necessary to avoid memory leaks

    return 0;
}

// Implement the other functions as previously described

// Example implementation for createNode
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
// Implement the advanced functions here

TreeNode* deleteNode(TreeNode *root, int value) {

}

TreeNode* findInOrderSuccessor(TreeNode *root, TreeNode *node) {

}

int findHeight(TreeNode *root) {

}

int isBalanced(TreeNode *root) {

}

TreeNode* convertToDoublyLinkedList(TreeNode *root) {

}

TreeNode* findLowestCommonAncestor(TreeNode *root, int value1, int value2) {

}
