#include <stdio.h>

int main()
{
    /*for (int i = 0; i < 100; i += 3)
    {
        printf("%d\n", i);
    }*/

    int i = 0;
    /*while(i < 100) {
        printf("%d\n", i);
        i+=3;
    }*/
    i = 0;
    do{
        printf("%d\n", i);
        i+=3;
    } while(i < 100);
    return 0;
}