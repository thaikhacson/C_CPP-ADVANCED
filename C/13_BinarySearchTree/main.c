#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>  // Added for string operations

typedef struct BstNode {
    char data[50];  // Assuming a maximum string length of 49 characters
    struct BstNode* left;
    struct BstNode* right;
} BstNode;

BstNode* GetNewNode(const char data[]) {
    BstNode* newNode = (BstNode*)malloc(sizeof(BstNode));
    strncpy(newNode->data, data, sizeof(newNode->data) - 1);  // Copy the string to the node's data
    newNode->data[sizeof(newNode->data) - 1] = '\0';  // Ensure null-terminated string
    newNode->left = newNode->right = NULL;
    return newNode;
}

BstNode* Insert(BstNode* root, const char data[]) {
    if(root == NULL) {
        root = GetNewNode(data);
    }
    else if(strcmp(data, root->data) <= 0) {
        root->left = Insert(root->left, data);
    } else {
        root->right = Insert(root->right, data);
    }
    return root;
}

int Search(BstNode* root, const char data[]) {
    if(root == NULL) return -1;
    else if(strcmp(data, root->data) == 0) return 1;
    else if(strcmp(data, root->data) < 0) return Search(root->left, data);
    else return Search(root->right, data);
}

int main() {
    BstNode* root = NULL;
    root = Insert(root, "12"); root = Insert(root, "34"); root = Insert(root, "56");
    root = Insert(root, "98"); root = Insert(root, "76"); root = Insert(root, "67");
    char number[50];  // Assuming a maximum string length of 49 characters
    printf("Enter string to be searched: ");
    scanf("%s", number);
    if(Search(root, number) == 1) printf("Found!");
    else printf("Not Found!");

    // Free allocated memory (not shown in the original code)
    // This can be done by calling a function that recursively frees the nodes.

    return 0;
}
