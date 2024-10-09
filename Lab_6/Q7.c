#include<stdio.h>
int main()
{
    int i;
    char ch;
    for(i = 1; i <= 30; i++) {
        // Calculate the character to print based on the row and column
        int row = (i - 1) / 5; // Get row number (0-based)
        int col = (i - 1) % 5; // Get column number (0-based)
        ch = 'A' + row + col;  // Calculate the character
        
        if((i<=5 || i>=26) || (i%5==1)) {
              printf("%c ", ch);
           }
       else if(i%5!=0)
             printf("  ");
       else 
             printf("%c", ch);
       
        if(i%5==0)
           printf("\n");
    }

    return 0;
}
// Time Wasted: 3 days
