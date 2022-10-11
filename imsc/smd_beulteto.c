#include <stdio.h>
#include <stdlib.h>

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

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
        if (command == 'L')
        {
            scanf("%d %d", &conveyor, &container);
            time += 0.1; // The time it takes to load the current part;
            partsUsedFromConveyor[conveyor - 1]++;

            // Moving to the conveyor belt;
            double distance = MAX(abs(-500 - currentX), abs(300 * conveyor - currentY));
            time += distance / velocity;
            
            // Updating current position
            currentX = -500;
            currentY = 300 * conveyor;
        }
        else if (command == 'P')
        {
            scanf("%d %d %d", &destX, &destY, &container); // coordinates are received in 0.1mm

            // Calculating the time it takes to reach the target
            double distance = MAX(abs(currentX - destX), abs(currentY - destY));
            time += distance / velocity + 0.1;

            // Updating current position
            currentX = destX;
            currentY = destY;
        }
    }

    printf("Assembly time: %.2lf s\nPart usage\n", time);
    for (int i = 0; i < 5; i++) {
        printf("\tTape %d: %d\n", i+1,  partsUsedFromConveyor[i]);
    }

    return 0;
}