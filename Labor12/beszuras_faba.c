#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node* left;
    struct _node* right;
} node;

void insert(node* root, int data) {
    node* currentNode = root;
    while(currentNode != NULL) {
        if(data < currentNode->data) {
            currentNode = currentNode->left;
        }
        else {
            currentNode = currentNode->right;
        }
        if(data > currentNode->left->data) {
            break;
        }
    }
    if(data < currentNode->data) {
        node* prevNext = currentNode->left;
        currentNode->left = (node*)malloc(sizeof(node));
        currentNode->left->data = data;
        currentNode->left->left = prevNext;
        return;
    }
    node* prevNext = currentNode->right;
        currentNode->right = (node*)malloc(sizeof(node));
        currentNode->right->data = data;
        currentNode->right->right = prevNext;
        return;
}