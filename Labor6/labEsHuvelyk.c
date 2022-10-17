#include <stdio.h>

typedef struct
{
    int foot;
    int inch;
} imperial;


double imperial_to_metric(imperial i)
{
    return i.foot * 0.3048 + i.inch * 0.3048 * 1 / 12;
}

imperial plus(imperial imperial1, imperial imperial2)
{
    imperial sum = { imperial1.foot + imperial2.foot,
                     imperial1.inch + imperial2.inch };
    if(sum.inch >= 12) {
        int foot = sum.inch / 12;
        sum.inch -= foot * 12;
        sum.foot += foot;
    }
    return sum;
}

int main() {
    int foot, inch;
    while(scanf("%d%d", &foot, &inch) == 2) {
        imperial imp = {foot, inch};
        printf("%.4lf ", imperial_to_metric(imp));
    }
    return 0;
}