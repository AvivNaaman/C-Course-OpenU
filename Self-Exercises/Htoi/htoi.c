#include <stdio.h>

#define MAXLENGTH 20

int main() 
{
    char input_string[MAXLENGTH];
    int input_val;
    fgets(input_string, MAXLENGTH, stdin);
    input_val = htoi(input_string);
    return 0;
}

int htoi(char string[]) {
    int i, result;
    int isNegative = string[0] == '-';
    for (i = (isNegative || string[0] == '+'); string[i] != '\n' && string[i] != '\0'; i++)
    {
        result *= 10;
        result += string[i];
    }
    return isNegative ? (-1)*result : result;
}