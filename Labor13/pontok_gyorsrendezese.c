#include <stdlib.h>

typedef struct {
    double x, y;
} point;

int filter(point* p1, point *p2) {
    if(p1->x * p1->x + p1->y * p1->y < p2->x * p2->x + p2->y * p2->y) {
        return 0;
    }
    return 1;
}

void sort_points(point points[], int size) {
    qsort(points, size, sizeof(point), filter);
}