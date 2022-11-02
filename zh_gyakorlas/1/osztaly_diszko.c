/*
Gale-Shapley algoritmus
Férfiak                     Nők
    A: F, G, E, H           E: A, B, C, D | B (igen)
    B: E, G, H, F           F: B, C, A, D | C (igen)
    C: H, E, F, G           G: C, B, D, A | A (igen)
    D: F, H, E, G           H: D, A, B, C | D (igen)
*/

#include <math.h>
#include <stdio.h>

enum sex {
    BOY,
    GIRL
};

typedef struct {
    enum sex sex;
    int height; // height in cm
} student;

int partner (student s1, student s2) {
    return s1.sex != s2.sex && abs(s1.height - s2.height) < 10 ? 1 : 0;
}

int num_partners (student students[], int size, int idx) {
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        if(i != idx && partner(students[idx], students[i]) == 1) {
            counter++;
        }
    }
    return counter;
}

void tallest_and_partners (student class[], int size, int* index, int* count) {
    *index = 0;
    for(int i = 0; i < size; i++) {
        if(class[i].height > class[*index].height) {
            *index = i;
        }
    }
    *count = num_partners(class, size, *index);
}

int main() {
    int index, count;
    student class[] = {
        {BOY, 180},
        {GIRL, 175},
        {GIRL, 160}
    };
    tallest_and_partners(class, 3, &index, &count);
    printf("%d %d", index, count);
    return 0;
}