#include <stdio.h>

char to_lower_case(char c) {
    if(c >= 'A' && c <= 'Z'){
        return c + 'a' - 'A';
    }
    return c;
}

int is_vowel(char c) {
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    c = to_lower_case(c);
    printf("%c", c);
    for(int i = 0; i < 5; i++) {
        if(vowels[i] == c) {
            return 1;
        }
    }
    return 0;
}

int main() {
    printf("%d", is_vowel('A'));
}