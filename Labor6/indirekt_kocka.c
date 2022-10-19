void cube(double sideLength, double* area, double* volume) {
    *volume = sideLength * sideLength * sideLength;
    *area = sideLength * sideLength * 6;
}