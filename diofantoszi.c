#include <stdio.h>

int main () {
    int a, b, c, x, y;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    x = 0;
    y = 0;

    while(x < 2147483647) {
        if(((c - a * x) / b) % 1 == 0) {
            y = ((c - a * x) / b);
            printf("%d %d\n", x, y);
        }
        x++;
    }

    return 0;
}