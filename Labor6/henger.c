#define _USE_MATH_DEFINES:

#define _USE_MATH_DEFINES
#include <math.h>

typedef struct henger cylinder;

struct henger {
    double height;
    double radius;
};

cylinder read_cylinder() {
    cylinder c;
    scanf("%lf%lf", &c.radius, &c.height);
    return c;
}

double cylinder_volume(cylinder c) {
    return c.radius * c.radius * M_PI * c.height; 
}

int main() {
    cylinder cylinders[10];

    for(int i = 0;i < 10; i++) {
        cylinders[i] = read_cylinder();
    }
    
    for(int i = 9; i >= 0; i--) {
        printf("%.2lf ", cylinder_volume(cylinders[i]));
    }

    return 0;
}