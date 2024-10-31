/*Create a function that reverses a given string and returns the reversed string. Use this function
in the main program to display the reversed string entered by the user.*/

#include<stdio.h>
#include<string.h>
void reverse(char str[]);
int main() {
    char str[100];
    printf("Enter a string:\t");
    scanf("%[^\n]s", str);
    reverse(str);
    printf("%s", str);
}

void reverse(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
