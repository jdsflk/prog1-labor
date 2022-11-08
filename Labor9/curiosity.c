#include <stdio.h>

typedef struct
{
    int day;
    int month;
    int year;

    int hour;
    int min;
    int sec;
} dateTime;

double fahrenheitToCelsius(double fahrenheit)
{
    return (fahrenheit - 32) * 5 / 9;
}

int main()
{
    FILE *fp1, *fp2;
    char file1[20], file2[20];

    //scanf("%s %s", &file1, &file2);

    fp1 = fopen("C:\\Users\\Asus\\Documents\\Egyetem\\Progi 1\\laborDebugger\\test.txt", "r");
    if(fp1 == NULL) {
        return 6;
    }
    fp2 = fopen("C:\\Users\\Asus\\Documents\\Egyetem\\Progi 1\\laborDebugger\\test2.txt", "a");

    dateTime dt;
    double temp;
    while (fscanf(fp1,
                  "MEASUREMENT_TIME %d/%d/%d %d:%d:%d\nTEMPERATURE %lfF\n",
                  &dt.month, &dt.day, &dt.year, &dt.hour, &dt.min, &dt.sec, &temp) == 7)
    {
        fprintf(fp2, "MERESI_IDO %d.%d.%d %c%d.%c%d.%c%d\nHOMERSEKLET %.1lfC\n",
                dt.year, dt.month, dt.day, dt.hour < 10 ? '0': '\0', dt.hour, dt.min < 10 ? '0' : '\0', dt.min, dt.sec < 10 ? '0' : '\0', dt.sec, fahrenheitToCelsius(temp));
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}