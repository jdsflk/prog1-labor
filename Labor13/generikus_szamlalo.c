int count_generic(char str[], int filterFunc(char)) {
    char current = str[0];
    int count = 0;
    int index = 0;
    while(current != '\0') {
        if(filterFunc(current)) {
            count++;
        }
        index++;
        current = str[index];
    }
    return count;
}