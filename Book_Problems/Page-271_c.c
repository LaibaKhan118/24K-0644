// Write a code that extracts part of the given string from specified position. the program should print the wle string if the number of characters to be extracted is 0
#include <stdio.h>

int main()
{
    char str[500];
    int p, ch;
    printf("Enter the String:\t");
    gets(str);
    printf("Enter the position from where you want to start extracting:\t");
    scanf("%d", &p);
    printf("Enter the number of characters you want to extract:\t");
    scanf("%d", &ch);
    if(ch == 0) {
        printf("%s\n",str);
    }
    else{
        for(int i = p-1; i <= (p+ch)-1; i++) {
            printf("%c", str[i]);
        }
    }
}
