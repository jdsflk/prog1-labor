#include <stdio.h>
 
int main()
{
    int num1, num2, temp;
    scanf("%d", &num1);
    scanf("%d", &num2);

    while(num1 != 0) {
        temp = num1;
        num1 = num2 % num1;
        num2 = temp;
    }

    printf("%d", num2);

    return 0;
}