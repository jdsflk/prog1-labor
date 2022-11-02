#include <stdio.h>

int main () {
    double currentPiece, sum = 0;
    while(scanf("%lf", &currentPiece) == 1) {
        if(sum + currentPiece - 2 >= 0) {
            printf("%.03lf ", 2 - sum);
            sum = 0;
        }
        sum += currentPiece;
    }
    printf("%0.3lf", 2 - sum);
    return 0;
}