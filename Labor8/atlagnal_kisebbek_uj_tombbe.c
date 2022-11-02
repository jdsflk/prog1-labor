#include <stdlib.h>

int* filter_average(int numbers[], int size, int *newSize) {
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += numbers[i];
    }

    double avg = sum / size;
    int length = 0;

    for (int i = 0; i < size; i++)
    {
        if(numbers[i] < avg) {
            length++;
        }
    }
    int* smallValues = (int *)malloc(length*sizeof(int));
    *newSize = 0;
    for (int i = 0; i < size; i++)
    {
        if(numbers[i] < avg) {
            smallValues[*newSize] = numbers[i];
            (*newSize)++;
        }
    }
    return smallValues; 
}