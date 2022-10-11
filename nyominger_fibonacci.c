#include <stdio.h>

int main()
{
    long long unsigned array[100];
    long long unsigned temp;
    scanf("%llu %llu", &array[0], &array[1]);

    if (array[0] + array[1] < array[0])
    {
        printf("1");
        return 0;
    }
    /*if (array[0] > array[1])
    {
        temp = array[0];
        array[0] = array[1];
        array[1] = temp;
    }*/

    for (int i = 0; i < 100; i++)
    {
        if (!(i % 2))
        {
            array[i] += array[i-1];
        }
        else
        {
            array[i-1] += array[i];
        }
        if (array[i-1] + array[i] < array[i-1])
        {
            if (array[i-1] > array[i])
            {
                printf("Array[0]: %llu, array[1]: %llu, index: %d\n", array[i-1], array[i], i + 1);
                return 0;
            }
            printf("Array[0]: %llu, array[1]: %llu, index: %d\n", array[i-1], array[i], i + 2);
            return 0;
        }
    }
    return 0;
}