#include <stdio.h>

int ipow(int base, int power)
{
    int product = 1;
    for (int i = 0; i < power; i++)
    {
        product *= base;
    }
    return product;
}

int expBySquaring(int base, int power)
{
    if (power < 0)
    {
        return expBySquaring(1 / base, -power);
    }
    else if (!power)
    {
        return 1;
    }
    else if (!(power % 2))
    {
        return expBySquaring(base * base, power / 2);
    }
    else if (power % 2)
    {
        return base * expBySquaring(base * base, (power - 1) / 2);
    }
}

int main() {}