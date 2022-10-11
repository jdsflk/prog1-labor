#include <stdio.h>

int main()
{
    int prev = 0;
    int current = 1;

    const int n = 10;

    printf("%d\n", prev);
    printf("%d\n", current);
    
    for(int i = 0; i < n - 2; i++) {
        prev = current - prev;
        current += prev;
        printf("%d\n", current);
    }
    return 0;
}