#include <stdio.h>

int main() {
    int lower, higher;

    scanf("%d", &lower);
    scanf("%d", &higher);

    printf("%d ", lower);

    for(int i = 1; lower + i <= higher; i++) {
        lower += i;
        printf("%d ", lower);
    }
    return 0;
}