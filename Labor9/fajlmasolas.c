#include <stdio.h>

int main() {
    char file1[30], file2[30];
    scanf("%s %s", &file1, &file2);

    FILE *fp1, *fp2;
    int status1, status2;

    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "a");

    char current;

    while(fscanf(fp1, "%c", &current) == 1) {
        fprintf(fp2, "%c", current);
    }

    status1 = fclose(fp1);
    status2 = fclose(fp2);
    return 0;
}