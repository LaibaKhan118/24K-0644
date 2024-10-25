//Q: Write a C program to generate a diamond shape pattern using nested loops. The program should take the number of rows for the upper half of the diamond as input from the user.
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of rows:\t");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = n-1; j > i; j--) {
                printf(" ");
            }
        for(int k = 0; k < i; k++) {
            printf("* ");
        }
        printf("\n");
    }
    for(int i = 0; i < n; i++) {
        printf(" ");
        for(int k = 0; k < i; k++) {
            printf(" ");
        }
        for(int k = n-2; k > i; k--) {
            printf("* ");
        }
        printf("\n");
    }    

    return 0;
}
