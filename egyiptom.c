#include <stdio.h>

int main () {
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);

    int denominator = 1;

    for(int i = 1; 1/i > m/n; i++) {
        denominator = i + 1;
    }
    print("%d ", denominator);
    

    printf("1/%d < %d/%d", denominator, m, n);

    return 0;
}