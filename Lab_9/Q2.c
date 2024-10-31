/*Create a C program that swaps the values of two integers using a user-defined function,
swapIntegers. The user inputs two integer values, and the program uses the function to swap
them. It should perform the swap and display the updated values.*/


#include <stdio.h>

void swapIntegers(int *a, int *b);
int main() {
    int num1, num2;
    printf("Enter Number 1:\t");
    scanf("%d", &num1);
    printf("Enter Number 2:\t");
    scanf("%d", &num2);
    swapIntegers(&num1, &num2);
    return 0;
}

void swapIntegers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;

    printf("Number 1 is: %d\n", *a);
    printf("Number 2 is: %d\n", *b);
}
