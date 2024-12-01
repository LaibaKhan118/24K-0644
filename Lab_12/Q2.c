/*Task 2: Write a program to implement the exchange or swap the values of 3 variables{a,b,c}. To
implement this, you need to write a function called swapped().
void swapped(int *aPtr, int *bPtr, int *cPtr);*/

#include <stdio.h>

void swapped(int *aPtr, int *bPtr, int *cPtr);

int main()
{
    int a, b, c;
    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);
    printf("Enter the value of c: ");
    scanf("%d", &c);
    swapped(&a, &b, &c);
    printf("\nSwapped values\na: %d\nb: %d\nc: %d\n", a, b, c);
    return 0;
}

void swapped(int *aPtr, int *bPtr, int *cPtr)
{
    int temp = *aPtr;
    *aPtr = *bPtr;
    *bPtr = *cPtr;
    *cPtr = temp;
}
