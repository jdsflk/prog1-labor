#include <stdio.h>

int interval(int first, int length) {
    int counter = 0;
    for (int num = first; num < first + length; num++) 
    { 
        int tens = num / 10; 
        int ones = num - tens * 10; 

        while(tens > 9) {
            tens -= 10;
        }
        if (ones > tens)
        {
            counter++;
        } 
    }
    return counter;
}

int main() {
    int first, last, min = -1;

    while (scanf("%d %d", &first, &last) == 2)
    {
        int current = interval(first, last);
        if(min == -1 || current < min) {
            min = current;
        }
    }
    printf("%d", min);
    return 0;
}