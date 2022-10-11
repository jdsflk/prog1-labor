#include <stdio.h>

int main () {
    float currentNum;
    float sum = 0;
    char c;

    while(scanf("%f", &currentNum) == 1) {
        sum += currentNum;
    }

    printf("%.3f\n", sum);

    while(scanf("%c", &c) == 1) {
        printf("%c", c);
    }
    return 0;
}