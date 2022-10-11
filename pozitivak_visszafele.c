#include <stdio.h>

int main()
{
    int array[100];
    int currentNum;
    int lastIndex = 0;

    scanf("%d", &currentNum);

    while(currentNum != 0) {
        array[lastIndex] = currentNum;
        lastIndex++;
        scanf("%d", &currentNum);
    }


    for (lastIndex-1; lastIndex >= 0; lastIndex--)
    {
        if (array[lastIndex - 1] > 0)
        {
            printf("%d ", array[lastIndex - 1]);
        }
    }

    return 0;
}