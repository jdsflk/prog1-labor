#include <stdlib.h>
#include <stdio.h>

typedef struct _node {
    int data;
    struct _node* left;
    struct _node* right;
} node;

typedef struct listelem
{
    node* data;
    struct listelem *next;
} listelem;

void push(listelem *stack, node* a)
{
    listelem *tail = stack;
    while(tail->next!= NULL) {
        tail = tail->next;
    }
    tail->next = (listelem*)malloc(sizeof(listelem));
    tail->next->data = a;
    tail->next->next = NULL;
}

node* pop(listelem *stack)
{
    listelem *tail = stack;
    while (tail->next != NULL && tail->next->next != NULL)
    {
        tail = tail->next;
    }
    node* data = tail->next->data;
    free(tail->next);
    tail->next = NULL;
    return data;
}

int leaf_nodes(node* root) {
    if(root == NULL) {
        return 0;
    }
    listelem* stack = (listelem*)malloc(sizeof(listelem));
    stack->next = (listelem*)malloc(sizeof(listelem));
    stack->next->data = root;
    stack->next->next = NULL;
    int count = 0;
    while(stack->next != NULL) {
        node* currentNode = pop(stack);
        if(currentNode->left == NULL && currentNode->right == NULL) {
            count++;
            continue;
        }
        if(currentNode->left != NULL) {
            push(stack, currentNode->left);
        }
        if(currentNode->right != NULL) {
            push(stack, currentNode->right);
        }
    }
    return count;
}

int main() {
    node* node1 = (node*)malloc(sizeof(node));
    node1->data = 30;
    node* node2 = (node*)malloc(sizeof(node));
    node2->data = 25;
    node* node3 = (node*)malloc(sizeof(node));
    node3->data = 20;
    node* node4 = (node*)malloc(sizeof(node));
    node4->data = 10;
    node* node5 = (node*)malloc(sizeof(node));
    node5->data = 22;
    node* node6 = (node*)malloc(sizeof(node));
    node6->data = 27;
    node* node7 = (node*)malloc(sizeof(node));
    node7->data = 28;
    node* node8 = (node*)malloc(sizeof(node));
    node8->data = 26;
    node* node9 = (node*)malloc(sizeof(node));
    node9->data = 40;
    node* node10 = (node*)malloc(sizeof(node));
    node10->data = 35;
    node* node11 = (node*)malloc(sizeof(node));
    node11->data = 33;
    node* node12 = (node*)malloc(sizeof(node));
    node12->data = 37;
    node* node13 = (node*)malloc(sizeof(node));
    node13->data = 44;
    node* node14 = (node*)malloc(sizeof(node));
    node14->data = 41;
    node* node15 = (node*)malloc(sizeof(node));
    node15->data = 47;

    node1->left = node2;
    node1->right = node9;

    node2->left = node3;
    node2->right = node6;

    node3->left = node4;
    node3->right = node5;

    node6->left = node8;
    node6->right = node7;

    node9->left = node10;
    node9->right = node13;

    node10->left = node11;
    node10->right = node12;

    node13->left = node14;
    node13->right = node15;

    node4->left = NULL;
    node4->right = NULL;
    node5->left = NULL;
    node5->right = NULL;
    node8->left = NULL;
    node8->right = NULL;
    node7->left = NULL;
    node7->right = NULL;
    node11->left = NULL;
    node11->right = NULL;
    node12->left= NULL;
    node12->right = NULL;
    node14->left = NULL;
    node14->right = NULL;
    node15->left = NULL;
    node15->right = NULL;
    printf("%d", leaf_nodes(NULL));
    return 0;
}