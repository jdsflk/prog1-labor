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

int main() {
    int array[10], count = 0;

    for(int i = 0; i < 10; i++) {
        scanf("%d", &array[i]);
    }
    for(int i = 0; i < 10; i++) {
        for(int j = i; j < 10; j++) {
            if(relative_primes(array[i], array[j])) {
                count++;
            }
        }
    }
    printf("%d", count);
    return 0;
}