#include <string.h>
#include <stdio.h>

void copy_nth_words(char str1[], char str2[], int n)
{
    int counter = 0;
    char *p;
    p = strtok(str1, " ");
    while (p != NULL)
    {
        if(counter % n == 0) {
            strcat(str2, p);
            strcat(str2, " ");
        }
        p = strtok(NULL, " ");
        counter++;
    }
}

int main()
{
    char str1[] = "cica hollo varju kutya mokus beka csiga";
    char str2[] = "";
    int n = 3;
    copy_nth_words(str1, str2, n);
    printf("%s", str2);
    return 0;
}