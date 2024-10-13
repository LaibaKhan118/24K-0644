/*Q: Write a program which identifies if a given string is a palindrome using arrays.*/

#include <stdio.h>

int main() {
    char str[500];
    printf("Enter a string:\t");
    scanf("%[^\n]s", str);
    char *ptr = str;
    int len = 0, palindrome = 0;
    
    while(*ptr != '\0') {
        len++;
        ptr++;
    }
    
    for(int i = 0; i < len/2; i++) {
        if(str[i] == str[len-i-1]){
            palindrome = 1;
        }
        else{
            palindrome = 0;
            break;
        }
    }
    
    if (palindrome == 1) {
        printf("This string is a palindrome\n");
    }
    else {
       printf("This string is not a palindrome\n"); 
    }
    return 0;
}
