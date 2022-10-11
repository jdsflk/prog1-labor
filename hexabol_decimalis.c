#include <stdio.h>

/*
    Test 1: 0 -> 0
    Test 2: 3 -> 3
    Test 3: a -> 10
    Test 4: f -> 15
    Test 5: F81 -> 3969
    Test 6: 2ded6952 -> 770533714
    Test 7: 3af5f763 -> 989198179
    Test 8: 220521fd -> 570761725

    No random test...
*/

int hexa_value (char c) {
      if((c >= '0' && c <= '9')){
        return c - '0';
      } 
      else if ((c >='a' && c <= 'f')) {
        return c - 'a' + 10;
      }
      else if ((c >='A' && c <= 'F')) {
        return c - 'A' + 10;
      }
      return -1; 
}

int main()
{
    char currentHexaDigit;
    int currentDecDigit, decNum;
    int len = 0;
  
    while (scanf("%c", &currentHexaDigit) != EOF) {
  
        currentDecDigit = hexa_value(currentHexaDigit);
        
        decNum = decNum * 16 + currentDecDigit; // Horner's rule
    }

    printf("%d", decNum);
    return 0;
}