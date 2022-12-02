#include <stdio.h>

int gcd(int num1, int num2)
{
    int temp;
    while (num1 != 0)
    {
        temp = num1;
        num1 = num2 % num1;
        num2 = temp;
    }
    return num2;
}

int relative_primes(int num1, int num2)
{
    return gcd(num1, num2) == 1 ? 1 : 0;
}

int main()
{
    int num1, num2, count = 0;
    while (scanf("%d %d", &num1, &num2) == 2)
    {
        if (relative_primes(num1, num2))
        {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}