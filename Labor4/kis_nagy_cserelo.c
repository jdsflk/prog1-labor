#include <stdio.h>

int main(void)
{
    char c;
    while (scanf("%c", &c) != EOF)
    {
        if (c >= 'a' && c <= 'z'){
            c = c + 'A' - 'a';
            printf("%c", c);
        }
        else if (c >= 'A' && c <= 'Z'){
            c = c + 'a' - 'A';
            printf("%c", c);
        }
        else {
            printf("%c", c);
        }
    }
    return 0;
}