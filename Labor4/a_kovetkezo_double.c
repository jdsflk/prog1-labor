#include <stdio.h>

int main() {
    double a, d;
    scanf("%lf", &a);

    if(a == 0.0) {
        return 0;
    }

    d = a;
    double sum = a + d;
    while(sum > a) {
        d*=0.5;
        sum = a + d;
    }

    printf("%.5E", (a + d * 2) - a);

    return 0;
}