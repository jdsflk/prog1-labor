void minmax (double numbers[], int size, double* min, double* max) {
    *min = numbers[0];
    *max = numbers[0];
    for(int i = 1; i < size; i++) {
        if(numbers[i] > *max) {
            *max = numbers[i];
        }
        else if (numbers[i] < *min) {
            *min = numbers[i];
        }
    }
}