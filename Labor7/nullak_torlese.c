#include <stdio.h>

int remove_zeros(int numbers[], int size)
{
    int newSize = size;
    for (int i = 0; i < size; i++)
    {
        if(numbers[i] == 0) {
            newSize--;
        }
    }
    
    for (int i = 0; i < size; i++)
    {
        if (numbers[i] == 0)
        {
            for (int j = 1; j < size; j++)
            {
                if (i + j < size && numbers[i + j] != 0)
                {
                    numbers[i] = numbers[i + j];
                    numbers[i + j] = 0;
                    break;
                }
            }
        }
    }
    return newSize;
}

int main()
{
    int array[] = {-2, -1, 1, 1, 2, 3, -1, -1, 2, 1, -1, 0, 2, -2, -2, -2, 3, 0};
    int newSize = remove_zeros(array, 18);
    for (int i = 0; i < 18; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\t%d", newSize);
    return 0;
}