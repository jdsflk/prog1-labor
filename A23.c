#include <stdio.h>

int main()
{
    int numbers[10] = {};
    for(int i = 0; i < 10; i++){
        printf("Please enter the %d. number! ", i+1);
        scanf("%d", &numbers[i]);
    }
    int biggestNum = numbers[0];
    for(int i = 1; i < 10; i++) {
        if(numbers[i] > biggestNum){
            biggestNum = numbers[i];
        }
    }
    printf("%d", biggestNum);
    return 0;
}