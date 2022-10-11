#include <stdio.h>

void firstOrLastRow(int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("x");
    }
}

int main()
{
    int size;
    scanf("%d", &size);

    firstOrLastRow(size);

    if(size == 1) {
        return 0;
    }

    printf("\n");

    for (int i = 0; i < size - 2; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (j == 0 || j == size - 1)
            {
                printf("x");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }

    firstOrLastRow(size);

    return 0;
}