#include <stdio.h>

int main()
{
    int side;
    scanf("%d", &side);
    printf("A kocka oldalhossza %d m\nA kocka terfogata %d m3\nA kocka felszine %d m2", side, side*side*side, 6*side*side);
    return 0;
}