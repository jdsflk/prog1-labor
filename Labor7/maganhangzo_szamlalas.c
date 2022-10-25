int count_vowels (char string[]) {
    int count = 0;
    while(*string != '\0') {
        if(is_vowel(*string)) {
            count++;
        }
        string++;
    }
    return count;
}