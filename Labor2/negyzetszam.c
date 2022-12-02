#include <stdio.h>
#include <math.h>

int main() {
    int num;
    scanf("%d", &num);

    for(int i = 1; i <= sqrt(num); i++) {
        if(i * i == num) {
            printf("Negyzetszam");
            return 0;
        }
    }

    printf("Nem negyzetszam");

    return 0;
}