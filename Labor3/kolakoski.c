#include <stdio.h>

int main()
{
    int current = 1;
    int prev;
    int currentLength = 1, prevLength = 1;

    printf("1 ");
    prev = current;
    current = 2;
    currentLength++;

    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < currentLength; i++)
        {
            printf("%d ", current);
        }

        prev = current;
        current = current == 2 ? 1 : 2;
        prevLength = currentLength;
        currentLength++;
    }

    return 0;
}
