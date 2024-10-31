/*Create a program that accepts a 2D array of strings (e.g., 5 words with a max length of 20
characters each). Determines if each word (row) is a palindrome. Outputs “Palindrome” or “Not
Palindrome” for each word. A palindrome is a word that reads the same forward and backward.
For example: &quot;madam&quot;, &quot;racecar&quot;, &quot;level&quot;, &quot;radar&quot;.*/

#include <stdio.h>
#include <string.h>

void palindrome(char str[]);
int main() {
    char str[5][20];
    for (int i = 0; i < 5; i++)
    {
        printf("Enter String %d:\t", i+1);
        scanf(" %[^\n]s", str[i]);
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        palindrome(str[i]);
    }
    
    return 0;
}

void palindrome(char str[]) {
    int len = strlen(str);
    int flag = 1;
    for (int i = 0; i < len/2; i++)
    {
        if (str[i] != str[len - 1 - i])
        {
            flag = 0;
            break;
        }
    }
    if(flag == 1) {
        printf("%s is a Palindrome\n", str);
    }
    else {
        printf("%s is a not Palindrome\n", str);
    }
}
