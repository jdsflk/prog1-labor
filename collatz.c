#include <stdio.h>

int main () {
    int element;
    scanf("%d", &element);

    int count = 0;

    while(element != 1) {
        if(element % 2 == 0) {
            element /= 2;
        }
        else {
            element = 3 * element + 1;
        }
        count++;
    }

    printf("%d", count);

    return 0;
}