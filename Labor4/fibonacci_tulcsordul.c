#include <stdio.h>

int main()
{
    long long unsigned array[2];
    scanf("%llu %llu", &array[0], &array[1]);

    if (array[0] + array[1] < array[0])
    {
        printf("1");
        return 0;
    }

    for (int i = 0; i < 100; i++)
    {
        long long unsigned temp = array[1];
        array[1] += array[0];
        array[0] = temp;
        if (array[0] + array[1] < array[0])
        {
            printf("%d", i+2);
            return 0;
        }
    }
    return 0;
}