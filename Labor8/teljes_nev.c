char* concatenate(char lastName[], char firstName[]) {
    int totalLength = 0;
    int currentIndex = 0;
    while (lastName[currentIndex] != '\0')
    {
       currentIndex++;
    }

    totalLength += currentIndex;
    currentIndex = 0;
    while (firstName[currentIndex] != '\0')
    {
        currentIndex++;
    }
    totalLength += currentIndex;
    
    currentIndex = 0;

    char* fullName = (char *)malloc((totalLength+2)*sizeof(char));
    if(fullName != 0) {
        while(lastName[currentIndex] != '\0') {
            fullName[currentIndex] = lastName[currentIndex];
            currentIndex++;
        }

        fullName[currentIndex] = ' ';
        
        int fullNameIndex = currentIndex + 1;
        currentIndex = 0;

        while (firstName[currentIndex] != '\0')
        {
            fullName[fullNameIndex] = firstName[currentIndex];
            currentIndex++;
            fullNameIndex++;
        }
        fullName[fullNameIndex] = '\0';
    }
    return fullName;
}