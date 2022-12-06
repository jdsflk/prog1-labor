#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node* left;
    struct _node* right;
} node;
void insert(node* root, int data) {
    node* currentNode = root;
    while(currentNode->left != NULL || currentNode->right != NULL) {
        if(data > currentNode->data) {
            currentNode = currentNode->right;
            continue;
        }
        if(data < currentNode->data) {
            currentNode = currentNode->left;
        }
    }
    if(data > currentNode->data) {
        currentNode->right = (node*)malloc(sizeof(node));
        currentNode->right->right = NULL;
        currentNode->right->left = NULL;
        currentNode->right->data = data;
        return;
    }
    if(data < currentNode->data) {
        currentNode->left = (node*)malloc(sizeof(node));
        currentNode->left->left = NULL;
        currentNode->left->right = NULL;
        currentNode->left->data = data;
    }
}