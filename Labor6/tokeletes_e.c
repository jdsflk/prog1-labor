#include <stdio.h>

int perfect(int num) {
    if(num == 1) {
        return 0;
    }
    int sum = 1;
    for(int i = 2; i * i < num; i++) {
        if(num % i == 0) {
            sum += i;
            sum += num / i;
        }
    }
    return sum == num;
}

int main(void) {
    int in = 6;
    int out = perfect(in);
    printf("%d\n", out); /* Ez nem feltétlenül szükséges,
        debug módban lehet figyelni out változó értékét. */
    return 0;
}