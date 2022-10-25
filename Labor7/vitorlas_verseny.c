#include <math.h>
#include <stdio.h>

typedef struct
{
    double x;
    double y;
} point;

typedef struct
{
    int hour;
    int minute;
    int second;
} time;

typedef struct
{
    point position;
    time interval;
} record;

double in_seconds(time t)
{
    return t.second + t.minute * 60 + t.hour * 3600;
}

double distance(point p1, point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double average_speed(record records[], size_t size) {
    double totalDistance = 0, totalTime = 0;
    for (int i = 1; i < size; i++)
    {
        totalDistance += distance(records[i].position, records[i-1].position);
        totalTime += in_seconds(records[i].interval);
    }
    return totalDistance / totalTime;
}