#include <stdio.h>
#include <float.h>
#include <math.h>

int main()
{
    int ind = 0;
    double num, x0;
    scanf("%lf %lf", &num, &x0);
    while (fabs(x0 * x0 - num) / num >= 10 * DBL_EPSILON)
    {
        printf("%d %.16E", ind, x0);
        x0 = 0.5 * x0 + num / (2 * x0);
        ind++;
    }
    return 0;
}