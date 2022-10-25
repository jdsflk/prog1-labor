void seven_to_zero(int numbers[], int size) {
    for (int i = 0; i < size; i++)
    {
        if (!(numbers[i] % 7))
        {
            numbers[i] = 0;
        }
    }
}