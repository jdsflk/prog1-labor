#include <stdio.h>

int a(int cards[]) {
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        if(cards[i]) {
            sum+=i;
        }
    }
    return sum;
}

void b (int cards[], int* pulledCount, int* dangerousCount) {
    int sum = a(cards);
    *pulledCount = 0;
    *dangerousCount = 0;
    for (int i = 0; i < 10; i++)
    {
        if(cards[i]) {
            (*pulledCount)++;
        }
        if(sum + cards[i] > 21) {
            (*dangerousCount)++;
        }
    }
}

int main() {
    int pulledCount = 0;
    int dangerousCount = 0;

    int deck[10] = {0};

    while(pulledCount >= dangerousCount && a(deck) < 21) {
        int currentValue;
        scanf("%d", &currentValue);
        deck[currentValue] = 1;
        b(deck, &pulledCount, &dangerousCount);
    }
    if(a(deck) <= 21) {
        printf("WIN");
    }
    else {
        printf("LOSE");
    }
    return 0;
}