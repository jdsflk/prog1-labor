#include <stdlib.h>

typedef struct _listelem
{
    double data;
    struct _listelem *next;
} listelem;

listelem *merge(listelem *a, listelem *b)
{
    if (a == NULL && b == NULL)
    {
        return NULL;
    }

    listelem *mergedList;

    if (a != NULL && (b == NULL || a->data < b->data))
    {
        mergedList = a;
        a = a->next;
    }
    else
    {
        mergedList = b;
        b = b->next;
    }

    listelem* mergedHead = mergedList;
    mergedList->next = NULL;
    
    listelem* mergedTail = mergedList->next;

    while (a != NULL || b != NULL)
    {
        if (b != NULL && a == NULL || b != NULL && b->data < a->data)
        {
            mergedList->next = b;
            b = b->next;
        }

        else
        {
            mergedList->next = a;
            a = a->next;
        }

        mergedList = mergedList->next;
        mergedList->next = NULL;
    }
    return mergedHead;
}

listelem *list_from_array(double t[], int n)
{
    listelem *last = NULL;
    int i;
    for (i = n - 1; i >= 0; i--)
    {
        listelem *new = (listelem *)malloc(sizeof(listelem));
        new->data = t[i];
        new->next = last;
        last = new;
    }
    return last;
}

void free_list(listelem *root)
{
    while (root != NULL)
    {
        listelem *next = root->next;
        free(root);
        root = next;
    }
}

int main()
{
    double array1[] = {1.0};
    double array0[] = {};

    double array4[] = {1.3, 3.2, 4.6, 7.0};
    double array3[] = {2.7, 2.9, 5.1};

    double array12[] = {2.0};

    merge(list_from_array(array1, 1), NULL);
    merge(list_from_array(array4, 4), list_from_array(array3, 3));
    merge(list_from_array(array1, 1), list_from_array(array12, 1));
    merge(NULL, NULL);
}