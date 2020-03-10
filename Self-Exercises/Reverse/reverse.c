#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void reverse_p(char s[], int start, int end);

int main() 
{
    char input_string[1024];
    printf("Enter a string: ");
    gets(input_string);
    reverse(input_string);
    puts(input_string);
    return 0;
}

void reverse(char s[]) {
    reverse_p(s, 0, strlen(s)-1);
}

void reverse_p(char s[], int start, int end)
{
    char temp;
    if (start >= end) return;
    temp = s[start];
    s[start] = s[end];
    s[end] = temp;
    reverse_p(s, start+1, end-1);
    return;
}