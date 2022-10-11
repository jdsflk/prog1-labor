#include <stdio.h>
int main()
{
    int curNum, prevNum;
    int isIncreasing = 0; // bool logikai valtozo, olyan int, ami csak 1 és 0 lehet
    scanf("%d", &curNum);
    printf("%d ", curNum);
    prevNum = curNum;
    scanf("%d", &curNum);
    if (curNum > prevNum)
    {
        isIncreasing = 1;
    }
    else if (curNum == prevNum)
    { // ==: egyenlő-e, =: legyen egyenlő
        printf("%d ", curNum);
        return 0;
    }
    printf("%d ", curNum);
    prevNum = curNum;
    while (scanf("%d", &curNum) == 1)
    {
        if (curNum > prevNum && isIncreasing == 1)
        {
            printf("%d ", curNum);
        }
        else if (curNum < prevNum && isIncreasing == 0)
        {
            printf("%d ", curNum);
        }
        else if (prevNum == curNum)
        {
            printf("Hello");
            return 0;
        }
        prevNum = curNum;
    }
    return 0;
}