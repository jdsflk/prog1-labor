#include <stdio.h>
#include <string.h>

int strCmp(char str1[], char str2[]) {
    for (int i = 0; i < strlen(str1); i++) {
        if(str1[i] != str2[i]) {
            return 0;
        }
    }
    return 1;
}

void toUpperCase(char str[]) {
    for(int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] + 'A' - 'a';
        }
    }
}

int main() {
    FILE *fp1, *fp2;
    char fileName[30], destFileName[30], charName[20];

    scanf("%s %s", fileName, charName);

    strcpy(destFileName, charName);
    strcat(destFileName, ".txt");

    fp1 = fopen(fileName, "r");
    fp2 = fopen(destFileName, "w");

    char currentLine[100];
    toUpperCase(charName);
    strcat(charName, "\n");

    while(fgets(currentLine, 100, fp1)) {
        if (strCmp(currentLine, charName) == 1)
        {
            do{
                fgets(currentLine, 100, fp1);
                for (int i = 1; i < strlen(currentLine); i++) {
                    fputc(currentLine[i], fp2);
                }
                if(feof(fp1)) {
                    break;
                }
            } while(currentLine[0] == '\t');
            fputc('\n', fp2);
        }
    }

    fclose(fp1);
    fclose(fp2);
}