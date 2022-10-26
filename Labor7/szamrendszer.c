#include <string.h>
#include <math.h>

unsigned int str_to_num(char str[], unsigned int base) {
    unsigned int num = 0;
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        num += (str[strlen(str) - i - 1] - '0') * pow(base, i);
    }
    return num;
}