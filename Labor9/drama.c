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

int main() {
    FILE *fp1, *fp2;
    char fileName[30], destFileName[30], charName[20];

    scanf("%s %s", fileName, charName);

    strcpy(destFileName, charName);
    strcat(destFileName, ".txt");

    fp1 = fopen(fileName, "r");
    fp2 = fopen(destFileName, "w");

    char currentLine[100];
    
    while(fgets(currentLine, 100, fp1)) {
        for (int i = 0; i < strlen(currentLine); i++)
        {
            if(currentLine[i] == '\n') {
                currentLine[i] = '\0';
            }
        }

        if (strCmp(currentLine, charName) == 1)
        {
            fgets(currentLine, 100, fp1);
            fprintf(fp2,"%s", currentLine);
        }
    }

    fclose(fp1);
    fclose(fp2);
}