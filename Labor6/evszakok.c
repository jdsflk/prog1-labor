#include <stdio.h>

enum season {
    SPRING,
    SUMMER,
    AUTUMN,
    WINTER
};

void print_season (enum season s) {
    switch (s)
    {
    case WINTER:
        printf("winter");
        break;
    case SPRING:
        printf("spring");
        break;
    case SUMMER:
        printf("summer");
        break;
    case AUTUMN:
        printf("autumn");
        break;
    default:
        break;
    }
}

enum season month2season(int num) {
    switch(num) {
        case 3:
        case 4:
        case 5:
            return SPRING;
        case 6:
        case 7:
        case 8:
            return SUMMER;
        case 9: 
        case 10:
        case 11:
            return AUTUMN;
        return WINTER;

    }
    /*if(num == 12 || num < 3) {
        return WINTER;
    }
    if(num > 2 && num < 6) {
        return SPRING;
    }
    if(num > 5 && num < 9) {
        return SUMMER;
    }
    return AUTUMN;*/
}

int main()
{
    /*int month;
    while(scanf("%d", &month) == 1) {
        print_season(month2season(month));
        printf(" ");
    }*/
    printf("%d", month2season(3));
    return 0;
}
