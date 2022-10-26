#include <string.h>
#include <stdio.h>

int first_unique (char str[]) {
    if(strlen(str) == 1) {
        return 0;
    }
    int index;
    for(int i = 0; i < strlen(str); i++) {
        for(int j = 0; j < strlen(str); j++) {
            if(i != j && str[i] == str[j]) {
                break;
            }
            if(j == strlen(str) - 1 && str[i] != str[j]) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    printf("%d", first_unique("baba"));
}