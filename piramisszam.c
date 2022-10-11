#include <stdio.h>

int pyramid(int n)
{
    int sum = 0;
    for (int i = 1; i < n + 1; i++)
    {
        sum += i * i;
    }
    return sum;
}

int main()
{

    return 0;
}
