#include <stdio.h>
#include <stdlib.h>

typedef struct _point_listelem {
    double x, y, z;
    struct _point_listelem* next;
} point_listelem;

void save(char fileName[], point_listelem* data) {
    FILE* destFile = fopen(fileName, "wb");
    point_listelem* current = data;
    while(current != NULL) {
        fwrite(&current->x, sizeof(double), 1, destFile);
        fwrite(&current->y, sizeof(double), 1, destFile);
        fwrite(&current->z, sizeof(double), 1, destFile);
        current = current->next;
    }
    fclose(destFile);
}

point_listelem* restore(char fileName[]) {
    FILE* origin = fopen(fileName, "rb");
    point_listelem* head = (point_listelem*)malloc(sizeof(point_listelem));

    fread(&head->x, sizeof(double), 1, origin);
    fread(&head->y, sizeof(double), 1, origin);
    fread(&head->z, sizeof(double), 1, origin);
    head->next = NULL;

    point_listelem* current = head;

    double x, y, z;

    while (fread(&x, sizeof(double), 1, origin) + fread(&y, sizeof(double), 1, origin) + fread(&z, sizeof(double), 1, origin) == 3) {
        current->next = (point_listelem*)malloc(sizeof(point_listelem));

        current->next->x = x;
        current->next->y = y;
        current->next->z = z;

        current->next->next = NULL;
        current = current->next;
    }
    fclose(origin);
    return head;
}

int main() {
    point_listelem* data = (point_listelem*)malloc(sizeof(point_listelem));
    point_listelem* next = (point_listelem*)malloc(sizeof(point_listelem));

    data->x = 4;
    data->y = 3.2;
    data->z = -7.6;
    data->next = next;

    next->x = 84.3;
    next->y = -612;
    next->z = 9;
    next->next = NULL;

    save("data.bin", data);
    free(data);
    free(next);

    point_listelem* restored = restore("data.bin");
    while (restored != NULL)
    {
        printf("%lf %lf %lf\n", restored->x, restored->y, restored->z);
        restored = restored->next;
    }

    return 0;
}