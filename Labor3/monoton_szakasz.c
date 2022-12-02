#include <stdio.h>

int main()
{
    int currentNumber, prevNumber;
    prevNumber = currentNumber;  // To pass the test when nothing is entered;
    int isIncreasing = 0;        // By default we assume that the series is decreasing
    scanf("%d", &currentNumber); // Reading the first value

    if (currentNumber != prevNumber) // First value gets printed if something is entered
    {
        printf("%d ", currentNumber);
    }
    prevNumber = currentNumber; // First value is now the previous

    scanf("%d", &currentNumber); // Reading the second value

    if (currentNumber == prevNumber)
    { // If it's the same as the previous, end the program
        return 0;
    }
    else
    { // Otherwise, the second number is printed
        printf("%d ", currentNumber);
    }

    if (currentNumber > prevNumber)
    {                     // If it's greater then the previous, it means that the series is increasing
        isIncreasing = 1; // Set isIncreasing to true
    }
    prevNumber = currentNumber;

    while (scanf("%d", &currentNumber) == 1)
    {
        // If the current number is greater and the series increased previously, print
        if (currentNumber > prevNumber && isIncreasing)
        {
            printf("%d ", currentNumber);
        }

        // If the current number is smaller and the series decreased before, print
        else if (currentNumber < prevNumber && !isIncreasing)
        {
            printf("%d ", currentNumber);
        }

        else
        {
            break;
        }
        prevNumber = currentNumber;
    }
    return 0;
}