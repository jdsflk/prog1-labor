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

int getFirstDigit(int num)
{
    return num / 10;
}

int getSecondDigit(int num)
{
    return num - 10 * (num / 10);
}

int main()
{
    FILE *fp1, *fp2;
    char file1[20], file2[20];

    scanf("%s %s", &file1, &file2);

    fp1 = fopen(file1, "r");
    if (fp1 == NULL)
    {
        return 6;
    }
    fp2 = fopen(file2, "a");

    dateTime dt;
    double temp;
    while (fscanf(fp1,
                  "MEASUREMENT_TIME %d/%d/%d %d:%d:%d\nTEMPERATURE %lfF\n",
                  &dt.month, &dt.day, &dt.year, &dt.hour, &dt.min, &dt.sec, &temp) == 7)
    {
        fprintf(fp2, "MERESI_IDO %d.%d%d.%d%d %d%d.%d%d.%d%d\nHOMERSEKLET %.1lfC\n",
                dt.year, 
                getFirstDigit(dt.day), getSecondDigit(dt.day),
                getFirstDigit(dt.month), getSecondDigit(dt.month),
                getFirstDigit(dt.hour), getSecondDigit(dt.hour),
                getFirstDigit(dt.min), getSecondDigit(dt.min),
                getFirstDigit(dt.sec), getSecondDigit(dt.sec),
                fahrenheitToCelsius(temp));
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}