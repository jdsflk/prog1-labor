#include <stdlib.h>

typedef struct _node {
    double data;
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

int negatives(node* root) {
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
        if(currentNode->data < 0) {
            count++;
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