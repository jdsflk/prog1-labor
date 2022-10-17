#include <stdio.h>
#include <stdlib.h>

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

double calculateDistance(int currentX, int currentY, int destX, int destY)
{
    return MAX(abs(currentX - destX), abs(currentY - destY));
}

void updatePosition(int *currentX, int *currentY, int destX, int destY)
{
    *currentX = destX;
    *currentY = destY;
}

void updateTime(double *time, double value)
{
    *time += value;
}

int main()
{
    char command;

    const int velocity = 5000;

    int conveyor, container;
    int destX, destY;
    int currentX = 0, currentY = 0;

    int partsUsedFromConveyor[5] = {0};

    double time = 0.0;

    while (scanf("%c", &command) != EOF)
    {
        double distance;
        if (command == 'L')
        {
            scanf("%d %d", &conveyor, &container);
            partsUsedFromConveyor[conveyor - 1]++;

            distance = calculateDistance(currentX, currentY, -500, 300);

            destX = -500;
            destY = 300 * conveyor;
        }
        else if (command == 'P')
        {
            scanf("%d %d %d", &destX, &destY, &container); // coordinates are received in 0.1mm

            distance = calculateDistance(currentX, currentY, destX, destY);
        }
        updateTime(&time, distance / velocity + 0.1);
        updatePosition(&currentX, &currentY, destX, destY);
    }

    printf("Assembly time: %.2lf s\nPart usage\n", time);
    for (int i = 0; i < 5; i++)
    {
        printf("\tTape %d: %d\n", i + 1, partsUsedFromConveyor[i]);
    }

    return 0;
}