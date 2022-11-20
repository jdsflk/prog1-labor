#include <stdlib.h>

typedef struct listelem {
    int data;
    struct listelem* next;
} listelem;

int main() {
    listelem* head = (listelem*)malloc(sizeof(listelem));
    listelem* tail = (listelem*)malloc(sizeof(listelem));

    head->next = tail;
    tail->next = NULL;

    listelem* empty = head;
}
