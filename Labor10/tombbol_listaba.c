#include <stdlib.h>

typedef struct list_elem
{
	double data;
	struct list_elem *next;
} list_elem, *list_ptr;

list_ptr array_to_list(double values[], int size) {
    list_ptr head = NULL;
    list_ptr* tail = &head;
    for (int i = 0; i < size; i++)
    {
        list_ptr temp = (list_ptr)malloc(sizeof(list_elem));
        temp->data = values[size - i - 1];
        temp->next = NULL;
        *tail = temp;
        tail = &(*tail)->next;
    }
    return head;
}