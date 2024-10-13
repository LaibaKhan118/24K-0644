/*Q: Write a program that calculates the length of a string using a pointer. Do not use the
built-in strlen() or sizeof() function. After length calculation reverse the string using
the same pointers*/

#include <stdio.h>
int main() {
    char str[500];
    printf("Enter a string:\t");
    scanf("%[^\n]s", str);
    char *ptr = str;
    int len = 0;
    char temp, *start, *end;
    
    while(*ptr != '\0') {
        len++;
        ptr++;
    }
    
    printf("String: %s\nLength: %d\n", str, len);
    
    start = str;
    end = str + len - 1;
    
    while(start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    
    printf("Reveresed string: %s", str);
    return 0;
}
