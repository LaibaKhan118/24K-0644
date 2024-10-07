#include<stdio.h>
int main()
{
    int i;
    for(i = 1; i <= 30; i++) {
        if((i > 1 && i < 5) || (i > 26 && i < 30)){
              printf("  ");
           }
       else 
             printf("* ");
        if(i % 5 == 0)
           printf("\n");
    }
}
