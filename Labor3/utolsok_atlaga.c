#include <stdio.h>

int main()
{
    float numbers[10];

    for (int i = 0; i < 10; i++)
    {
        numbers[i] = 0;
    }

    int index = 0;
    float sum = 0;
    float currentNumber;

    while (scanf("%f", &currentNumber) == 1)
    {
        numbers[index] = currentNumber;

        index++;

        if (index == 10)
        {
            index = 0;
        }
    }

    index = 0;
    for (int i = 0; i < 10; i++)
    {
        if (numbers[i] != 0 || (i != 9 && i != 0 && numbers[i - 1] != 0 && numbers[i] == 0 && numbers[i + 1] != 0))
        {
            index++;
        }
        sum += numbers[i];
    }

    printf("%.3f", sum / index);

    return 0;
}
