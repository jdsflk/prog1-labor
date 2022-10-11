#include <stdio.h>

int main() {
    float sum = 0;
    float currentNum;
    float count = 0;

    scanf("%f", &currentNum);

    while(currentNum != 0) {
        sum += currentNum;
        count+=1.0;
        scanf("%f", &currentNum);
    }

    printf("%.2f", sum/count);
    return 0;
}