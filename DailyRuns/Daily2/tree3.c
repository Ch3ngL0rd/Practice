#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct QueueNode {
    TreeNode *treeNode;
    struct QueueNode *next;
} QueueNode;

// Function prototypes
TreeNode* createNode(int value);
TreeNode* insert(TreeNode *root, int value);
void inorderTraversal(TreeNode *root, int *result, int *index);
void preorderTraversal(TreeNode *root, int *result, int *index);
void postorderTraversal(TreeNode *root, int *result, int *index);
void levelOrderTraversal(TreeNode *root, int *result, int *index);
void assertArrayEqual(int *arr1, int *arr2, int size, const char* message);

QueueNode* createQueueNode(TreeNode *node);
void enqueue(QueueNode **front, QueueNode **rear, TreeNode *node);
TreeNode* dequeue(QueueNode **front);

int main() {
    TreeNode *root = NULL;

    // Create a BST for testing
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);

    // Arrays to store traversal results
    int inorderResult[6], preorderResult[6], postorderResult[6];
    int index;

    // Perform traversals and store the results
    index = 0;
    inorderTraversal(root, inorderResult, &index);
    int expectedInorder[6] = {3, 5, 7, 10, 12, 15};
    assertArrayEqual(inorderResult, expectedInorder, 6, "In-order traversal failed");

    index = 0;
    preorderTraversal(root, preorderResult, &index);
    int expectedPreorder[6] = {10, 5, 3, 7, 15, 12};
    assertArrayEqual(preorderResult, expectedPreorder, 6, "Pre-order traversal failed");

    index = 0;
    postorderTraversal(root, postorderResult, &index);
    int expectedPostorder[6] = {3, 7, 5, 12, 15, 10};
    assertArrayEqual(postorderResult, expectedPostorder, 6, "Post-order traversal failed");

    printf("All traversal tests passed!\n");

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

// Implement the createNode and insert functions as before

void inorderTraversal(TreeNode *root, int *result, int *index) {
    // Implement in-order traversal
    // Store values in 'result' array and increment 'index'
    if (root == NULL) {
	return;
    }
    inorderTraversal(root->left,result,index);
    result[*index] = root->value;
    (*index)++;
    inorderTraversal(root->right,result,index);
}

void preorderTraversal(TreeNode *root, int *result, int *index) {
    // Implement pre-order traversal
    // Store values in 'result' array and increment 'index'
    if (root == NULL) {
	return;
    }
    result[*index] = root->value;
    (*index)++;
    preorderTraversal(root->left,result,index);
    preorderTraversal(root->right,result,index);
}

void postorderTraversal(TreeNode *root, int *result, int *index) {
    // Implement post-order traversal
    // Store values in 'result' array and increment 'index'
    if (root == NULL) {
	return;
    }
    postorderTraversal(root->left,result,index);
    postorderTraversal(root->right,result,index);
    result[*index] = root->value;
    (*index)++;
}

void assertArrayEqual(int *arr1, int *arr2, int size, const char* message) {
    for (int i = 0; i < size; i++) {
        assert(arr1[i] == arr2[i] && message);
    }
}
