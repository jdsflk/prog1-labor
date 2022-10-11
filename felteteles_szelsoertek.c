#include <stdio.h>

int main () {
    int currentNum;
    int max = 0;
    int min = 0;

    while(scanf("%d", &currentNum) == 1){
        if(currentNum > 0) {
            if(currentNum < max || max == 0) {
                max = currentNum;
            }
        }
        else if (currentNum < 0) {
            if(currentNum > min || min == 0) {
                min = currentNum;
            }
        }
    }

    if(min!= 0) {
        printf("%d ", min);
    }
    else {
        printf("--- ");
    }
    if(max != 0) {
        printf("%d", max);
    }
    else {
        printf("--- ");
    }

    return 0;
}