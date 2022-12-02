#include <stdio.h>

int main () {
    int category, salary;
    scanf("%d", &category);
    scanf("%d", &salary);

    switch(category){
        case 0:
        {
            printf("Bonus: 0 EUR");
            break;
        }
        case 1:
        {
            printf("Bonus: 1000 EUR");
            break;
        }
        case 2:
        {
            printf("Bonus: %d EUR", salary * 10 / 100);
            break;
        }
        case 3:
        {
            printf("Bonus: %d EUR", salary * 10 / 100 + 1000);
            break;
        }
        default:
        {
            printf("INVALID\nBonus: 0 EUR");
        }
    }

    return 0;
}