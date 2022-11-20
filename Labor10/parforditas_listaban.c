#include <stdlib.h>

typedef struct _listelem {
    int a;
    struct _listelem* next;
} listelem;

void reverse_pairs(listelem* head) {
    listelem* prevItem = head;
    listelem* currentItem = head->next;
    while(currentItem->next != NULL && currentItem->next->next!= NULL) {
        prevItem->next = currentItem->next;
        currentItem->next = currentItem->next->next;
        prevItem->next->next = currentItem;

        prevItem = prevItem->next->next;
        currentItem = prevItem->next;
    }
}