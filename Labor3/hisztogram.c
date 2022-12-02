#include <stdio.h>

int main()
{
    int currentNumber;
    int grades[5] = {0, 0, 0, 0, 0};

    while (scanf("%d", &currentNumber) == 1)
    {
        grades[currentNumber - 1]++;
    }
    printf("5: %d db\n4: %d db\n3: %d db\n2: %d db\n1: %d db\n", grades[4], grades[3], grades[2], grades[1], grades[0]);
    return 0;
}