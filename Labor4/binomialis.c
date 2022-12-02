#include <stdio.h>

int main(void)
{
    long long unsigned num, denom, b = 1;

    scanf("%llu %llu", &num, &denom);

    if (num - denom < denom)
    {
        denom = num - denom;
    }
    for (int i = 1; denom >= i; i++)
    {
        b = b * (num - i + 1);
        b /= i;
    }

    printf("%llu", b);
    return 0;
}