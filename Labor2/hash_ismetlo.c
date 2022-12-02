#include <stdio.h>

int main() {
    int hashNum;
    scanf("%d", &hashNum);

    if(hashNum > 100) {
        hashNum = 100;
    }

    for(int i = 0; i < hashNum; i++) {
        printf("#");
    }

    return 0;
}