#include<stdio.h>
int main()
{
    int i;
    for(i = 1; i <= 30; i++) {
        if((i<=5 || i>=26) || (i%5==1)) {
              printf("* ");
           }
       else if(i%5!=0)
             printf("  ");
       else 
             printf("*");
        if(i%5==0)
           printf("\n");
    }
}
// time wasted: 5 hours
