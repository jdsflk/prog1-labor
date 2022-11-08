#include <stdio.h>

int main () {
    FILE *fp1, *fp2;
    int status1, status2;

    fp1 = fopen("numbers.txt", "r");
    if(fp1 == NULL) {
        return 1;
    }

    fp2 = fopen("positive_numbers.txt", "w");

    double current;

    while (fscanf(fp1, "%lf", &current) == 1)
    {
        if(current > 0) {
            fprintf(fp2, "%0.4lf ", current);
        }
    }
    
    fclose(fp1);
    fclose(fp2);
    return 0;
}