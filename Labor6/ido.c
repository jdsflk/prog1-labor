#include <stdio.h>

typedef struct time time;

struct time {
    int hour;
    int min;
    int sec;
};

int time2sec (time t) {
    return 3600 * t.hour + 60 * t.min + t.sec;
}

time sec2time (int s) {
    time t;
    if(s < 0) {
        if(s < -86400) {
            s += (-s/86400) * 86400;
        }
        int hours = s / 3600;
        s -= hours * 3600;
        int minutes = s / 60;
        s -= minutes * 60;

        t.hour = 23 +  hours;
        t.min = 59 + minutes;
        t.sec = 60 + s;

        return t;
    }
    t.hour = s / 3600;
    s -= t.hour * 3600;
    t.min = s / 60;
    s -= t.min * 60;
    t.sec = s;

    if(t.hour > 23 && (t.min != 0 || t.sec != 0)) {
        t.hour -= 24;
    }

    return t;
}

time timeplus (time time1, time time2) {
    return sec2time(time2sec(time1) + time2sec(time2));
}

int timecmp (time time1, time time2) {
    if(time2sec(time1) > time2sec(time2) || time2sec(time1) == time2sec(time2)){
        time1.hour *= -1;
        time1.min *= -1;
        time1.sec *= -1;
        return time2sec(timeplus(time1, time2));
    }
    else {
        time2.hour *= -1;
        time2.min *= -1;
        time2.sec *= -1;
        return time2sec(timeplus(time1, time2)) - 86400;
    }
}

int main(void)
{
    time workout_begins = {1, 0, 0};
    time workout_ends = {1, 0, 1};
    printf("%d", timecmp(workout_begins, workout_ends));
    return 0;
}