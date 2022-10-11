#include <stdio.h>

int main()
{
    int a, b, c;
    printf("What's the first side? ");
    scanf("%d", &a);

    printf("What's the second side? ");
    scanf("%d", &b);

    printf("What's the third side? ");
    scanf("%d", &c);

    if(a+b > c && b+c > a && a+c > b) {
        printf("This could be a triangle.");
        return 0;
    }
    printf("This can't be a triangle.");
    return 0;
}